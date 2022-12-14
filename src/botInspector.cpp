/**
 * @file botInspector.cpp
 * @author Madhu Narra Chittibabu (mnarrach@umd.edu)
 * @author Koundinya Vinnakota (vkd@umd.edu)
 * @author Sharmitha Ganeshan (sganesan@umd.edu)
 * @brief This file controls the robot's position .
 * @version 0.1
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/botInspector.hpp"

BotInspector::BotInspector() : Node("botInspector") {
  current_position.position.x = 0.0;
  next_position.position.x = 0.0;
}

void BotInspector::moveToLocation() {
  pose_publisher_ = this->create_publisher<BOT_POSE>("/goal_pose", 10);
  std::shared_ptr<rclcpp::Node> odom_node =
      rclcpp::Node::make_shared("odom_node");

  auto odom_subscriber = odom_node->create_subscription<ODOMETRY>(
      "odom", 10, std::bind(&BotInspector::inspectionCallback, this, _1));

  BOT_POSE goal_pose_;

  goal_pose_.header.frame_id = "map";
  goal_pose_.header.stamp.sec = 0;
  goal_pose_.header.stamp.nanosec = 0;
  goal_pose_.pose.position.x = goal_x_;
  goal_pose_.pose.position.y = goal_y_;
  goal_pose_.pose.position.z = 0;
  goal_pose_.pose.orientation.x = 0;
  goal_pose_.pose.orientation.y = 0;
  goal_pose_.pose.orientation.z = 0;
  goal_pose_.pose.orientation.w = 1;

  while (!pose_flag) {
    rclcpp::spin_some(odom_node);
    pose_publisher_->publish(goal_pose_);
    RCLCPP_INFO(this->get_logger(), "Moving to inspect location");
    rclcpp::sleep_for(500ms);
  }
  pose_flag = false;
}

void BotInspector::setGoal(float x, float y) {
  goal_x_ = x;
  goal_y_ = y;
}

float BotInspector::getGoalx() { return goal_x_; }

float BotInspector::getGoaly() { return goal_y_; }

void BotInspector::rotateInspector() {
  twist_publisher_ = this->create_publisher<BOT_ROTATE>("/cmd_vel", 10);

  bot_check_.angular.z = 0.5;

  int count = 20;

  while (count) {
    rclcpp::spin_some(bot_rotate_node);
    twist_publisher_->publish(bot_check_);
    RCLCPP_INFO(this->get_logger(), "Looking around..");
    count--;
    rclcpp::sleep_for(500ms);
  }
}

void BotInspector::resumeInspection() {
  // pose_publisher_ = this->create_publisher<BOT_POSE>("goal_pose", 10);

  std::shared_ptr<rclcpp::Node> odom_node_1 =
      rclcpp::Node::make_shared("odom_node_1");

  auto odom_subscriber = odom_node_1->create_subscription<ODOMETRY>(
      "odom", 10, std::bind(&BotInspector::resumeInspectionCallback, this, _1));

  BOT_POSE goal_pose_1;

  goal_pose_1.header.frame_id = "map";
  goal_pose_1.header.stamp.sec = 0;
  goal_pose_1.header.stamp.nanosec = 0;
  goal_pose_1.pose.position.x = 0;
  goal_pose_1.pose.position.y = 0;
  goal_pose_1.pose.position.z = 0;
  goal_pose_1.pose.orientation.x = 0;
  goal_pose_1.pose.orientation.y = 0;
  goal_pose_1.pose.orientation.z = 0;
  goal_pose_1.pose.orientation.w = 1;

  while (!pose_flag) {
    rclcpp::spin_some(odom_node_1);
    pose_publisher_->publish(goal_pose_1);
    RCLCPP_INFO(this->get_logger(), "Going back to base station.");
    rclcpp::sleep_for(500ms);
  }
}

void BotInspector::inspectionCallback(const ODOMETRY::SharedPtr odom_msg_i) {
  if ((std::abs(static_cast<int>(odom_msg_i->pose.pose.position.x - goal_x_)) <
       0.5) &&
      (std::abs(static_cast<int>(odom_msg_i->pose.pose.position.y - goal_y_)) ==
       0)) {
    pose_flag = true;
    RCLCPP_INFO(this->get_logger(), "Now, Inspecting the location!");
  }
}

void BotInspector::resumeInspectionCallback(
    const ODOMETRY::SharedPtr odom_msg_r) {
  if ((std::abs(static_cast<int>(odom_msg_r->pose.pose.position.x)) == 0) &&
      (std::abs(static_cast<int>(odom_msg_r->pose.pose.position.y)) == 0)) {
    pose_flag = true;

    RCLCPP_INFO(this->get_logger(),
                "Reached the base station. Inspection finished!");
  }
}
