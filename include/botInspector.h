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

class BotInspector : public rclcpp::Node {

    public:
        BotInspector();


        void inspection();

        void moveToLocation();

        void resumeInspection();


    private:
        geometry_msgs::msg::Pose current_position;
        geometry_msgs::msg::Pose next_position;
        ODOMETRY::SharedPtr odom_msg_;
        PUB pose_publisher_;
        TIMER timer_;
        bool pose_flag = false;

        void inspectionCallback(const ODOMETRY::SharedPtr odom_msg_i);
        void resumeInspectionCallback(const ODOMETRY::SharedPtr odom_msg_r);

        float goal_x = -2.5;
        float goal_y = -3.5;



};