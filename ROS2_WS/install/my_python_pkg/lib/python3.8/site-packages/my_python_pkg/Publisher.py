#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String

class MyPublisher(Node):
    def __init__(self):
        super().__init__("publisher_node")

        self.name = "Iron Man"
        self.publisher_ = self.create_publisher(String, "publisher_node", 10)
        self.timer_ = self.create_timer(0.5, self.publish_message)
        self.get_logger().info("Publisher is publishing")


    def publish_message(self):
        msg = String()
        msg.data = "Hello this is " + str(self.name) + " from publiser node"
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = MyPublisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()