#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include <memory>

void mysub_callback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    RCLCPP_INFO(rclcpp::get_logger("node_dxlsub"),
                "Received message: x=%.2f, y=%.2f, z=%.2f",
                msg->x, msg->y, msg->z);
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("node_dxlsub");

    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    auto mysub = node->create_subscription<geometry_msgs::msg::Vector3>(
        "topic_dxlpub", qos_profile, mysub_callback);

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
