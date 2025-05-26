#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "dxl/dxl.hpp"
#include <iostream>
#include <string>
#include <memory>

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("node_dxlpub_cin");
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    auto mypub = node->create_publisher<geometry_msgs::msg::Vector3>("topic_dxlpub", qos_profile);

    geometry_msgs::msg::Vector3 vel;

    std::string input;
    int goal1 = 0, goal2 = 0;
    int vel1 = 0, vel2 = 0;

    rclcpp::WallRate loop_rate(20.0);  // 20Hz

    while (rclcpp::ok())
    {
        std::cout << "Enter command (f: forward, b: back, l: left, r: right, s or space: stop): ";
        std::cin >> input;

        if (input == "s" || input == " ")      { goal1 = 0;   goal2 = 0; }
        else if (input == "f")                 { goal1 = 50;  goal2 = -50; }
        else if (input == "b")                 { goal1 = -50; goal2 = 50; }
        else if (input == "l")                 { goal1 = -50; goal2 = -50; }
        else if (input == "r")                 { goal1 = 50;  goal2 = 50; }
        else                                   { goal1 = 0;   goal2 = 0; }

        // 목표 속도에 부드럽게 접근
        while ((vel1 != goal1 || vel2 != goal2) && rclcpp::ok()) {
            if (goal1 > vel1) vel1 += 5;
            else if (goal1 < vel1) vel1 -= 5;

            if (goal2 > vel2) vel2 += 5;
            else if (goal2 < vel2) vel2 -= 5;

            vel.x = vel1;
            vel.y = vel2;
            vel.z = 0.0;

            RCLCPP_INFO(node->get_logger(), "Publishing: x=%.2f, y=%.2f", vel.x, vel.y);
            mypub->publish(vel);
            loop_rate.sleep();
        }
    }

    rclcpp::shutdown();
    return 0;
}
