#include "rclcpp/rclcpp.hpp"


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("CPP_Test");
    RCLCPP_INFO(node->get_logger(), "Hello this is CPP Node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}