#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class PublisherNode : public rclcpp::Node{
    public:
    PublisherNode() : Node("Publisher"), publisher_name_("My Publisher"){
        publisher_ = this->create_publisher<example_interfaces::msg::String>("Publisher_Message", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&PublisherNode::publishNews, this));
        RCLCPP_INFO(this->get_logger(), "Publisher Node has started!");
    }

    private:
    void publishNews(){
        auto msg = example_interfaces::msg::String();
        msg.data = std::string("Hi this is ") + publisher_name_ + std::string(" from publishing node!");
        publisher_->publish(msg);
    }

    std::string publisher_name_;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}