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
using PUB_TWIST = rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr;
using TIMER = rclcpp::TimerBase::SharedPtr;
using ODOMETRY = nav_msgs::msg::Odometry;
using namespace std::chrono_literals;
using std::chrono::duration;
using BOT_POSE = geometry_msgs::msg::PoseStamped;
using BOT_ROTATE = geometry_msgs::msg::Twist;
/**
 * @brief This is the botinspector class, controls the pose of the bot
 * 
 */
class BotInspector : public rclcpp::Node {

    public:
        BotInspector();
        /**
         * @brief This function moves the bot Inspector to a defined location with a automatically computed path
         * 
         */
        void moveToLocation();
        /**
         * @brief This function gets the bot inspector back to the station coordinates.
         * 
         */
        void resumeInspection();
        /**
         * @brief This function controls the rotation of the bot after reaching a specific goal pose
         * 
         */
        void rotateInspector();


    private:
        geometry_msgs::msg::Pose current_position;
        geometry_msgs::msg::Pose next_position;
        ODOMETRY::SharedPtr odom_msg_;
        PUB pose_publisher_;
        PUB_TWIST twist_publisher_;
        TIMER timer_;
        bool pose_flag = false;
        /**
         * @brief This is the subscriber callback function of the moveToLocation controller.
         * 
         * @param odom_msg_i 
         */
        void inspectionCallback(const ODOMETRY::SharedPtr odom_msg_i);
        /**
         * @brief This is the subscriber callback for the resumeInspection function which returns the bot to the station location.
         * 
         * @param odom_msg_r 
         */
        void resumeInspectionCallback(const ODOMETRY::SharedPtr odom_msg_r);

        float goal_x = 0.0;
        float goal_y = -1.5;

        BOT_ROTATE bot_check_;
        std::shared_ptr<rclcpp::Node> bot_rotate_node = rclcpp::Node::make_shared("bot_rotate_node");


};