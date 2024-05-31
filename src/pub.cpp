#include "psub2-2/pub.hpp"

//auto msg = geometry_msgs::msg::Vector3();

Pub::Pub() : Node("mypub"), count_(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    pub_ = this->create_publisher<geometry_msgs::msg::Vector3>("mytopic", qos_profile);
    timer_ = this->create_wall_timer(1s, std::bind(&Pub::publish_msg, this));
   // auto msg = geometry_msgs::msg::Vector3();
    //std::cin>>msg.x>>msg.y>>msg.z;
}
void Pub::publish_msg()
{
    static auto msg = geometry_msgs::msg::Vector3();
    msg.x += 1, msg.y += 1, msg.z += 1;
    RCLCPP_INFO(this->get_logger(), "Publish: %lf %lf %lf", msg.x, msg.y, msg.z);
    pub_->publish(msg);
}
