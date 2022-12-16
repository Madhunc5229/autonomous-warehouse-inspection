/**
 * @file beacon.hpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com)
 * @brief This file contains declarations for beacon class
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"

using std::placeholders::_1;
using PUB = rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr;
using TIMER = rclcpp::TimerBase::SharedPtr;
using ODOMETRY = nav_msgs::msg::Odometry;
using namespace std::chrono_literals;
using std::chrono::duration;
using BOT_POSE = geometry_msgs::msg::PoseStamped;

using ARUCO_TYPE = geometry_msgs::msg::Pose;

/**
 * @brief this is a beacon class
 *
 */
class Beacon : public rclcpp::Node {
 public:
  Beacon();

  /**
   * @brief This the aruco call back function
   *
   * @param aruco_msg
   */
  void arucoCallback(const ARUCO_TYPE::SharedPtr aruco_msg);
};
