#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "dxl/dxl.hpp"
#include <memory>

void mysub_callback(rclcpp::Node::SharedPtr node, Dxl& dxl, const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    RCLCPP_INFO(node->get_logger(), "Received message: %f,%f", msg->x, msg->y);
    dxl.setVelocity((int)msg->x, (int)msg->y);
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    Dxl dxl;
    auto node = std::make_shared<rclcpp::Node>("node_dxlpub_cin");

    if (!dxl.open()) {
        RCLCPP_ERROR(node->get_logger(), "dynamixel open error");
        rclcpp::shutdown();
        return -1;
    }

    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    auto mysub = node->create_subscription<geometry_msgs::msg::Vector3>(
        "topic_dxlpub", qos_profile,
        [node, &dxl](const geometry_msgs::msg::Vector3::SharedPtr msg) {
            mysub_callback(node, dxl, msg);
        });

    rclcpp::spin(node);

    dxl.close();
    rclcpp::shutdown();

    return 0;
}
