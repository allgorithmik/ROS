#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String

class SubscriberNode(Node):

    def __init__(self):
        super().__init__("Subscriber")
        self.subscriber_ = self.create_subscription(
            String, "publisher_node", self.callback_robot_news, 10)
        self.get_logger().info("Subscriber has started")

    def callback_robot_news(self, msg):
        self.get_logger().info(msg.data)

    

def main(args=None):
        rclpy.init(args=args)
        node = SubscriberNode()
        rclpy.spin(node)
        rclpy.shutdown()

if __name__ == "__main__":
    main()
