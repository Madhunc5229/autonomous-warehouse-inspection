#pragma once
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <memory>
#include <iostream>
#include <vector>
#include <chrono>


using std::placeholders::_1;
using PUB = rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr;
using TIMER = rclcpp::TimerBase::SharedPtr;
using ODOMETRY = nav_msgs::msg::Odometry;
using namespace std::chrono_literals;
using std::chrono::duration;
using BOT_POSE = geometry_msgs::msg::PoseStamped;

using ARUCO_TYPE = geometry_msgs::msg::Pose;



class Beacon : public rclcpp::Node{
    public:
        Beacon();

    private:
        void arucoCallback(const ARUCO_TYPE::SharedPtr aruco_msg);
        

};