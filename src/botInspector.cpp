#include "../include/botInspector.h"



BotInspector::BotInspector() : Node("botInspector") {
    current_position.position.x = 0.0;
    next_position.position.x = 0.0;

}


void BotInspector::moveToLocation(){
    pose_publisher_ = this->create_publisher<BOT_POSE>("/goal_pose", 10);
    std::shared_ptr<rclcpp::Node> odom_node = rclcpp::Node::make_shared("odom_node");

    auto odom_subscriber = odom_node->create_subscription<ODOMETRY>("odom", 10, std::bind(&BotInspector::inspectionCallback, this, _1));

    BOT_POSE goal_pose_;

    goal_pose_.header.frame_id = "map";
    goal_pose_.header.stamp.sec = 0;
    goal_pose_.header.stamp.nanosec = 0;
    goal_pose_.pose.position.x = goal_x ;
    goal_pose_.pose.position.y = goal_y;
    goal_pose_.pose.position.z = 0;
    goal_pose_.pose.orientation.x = 0;
    goal_pose_.pose.orientation.y = 0;
    goal_pose_.pose.orientation.z = 0;
    goal_pose_.pose.orientation.w = 1;

    while(!pose_flag){
        rclcpp::spin_some(odom_node);
        pose_publisher_->publish(goal_pose_);
        RCLCPP_INFO(this->get_logger(), "Publishing goal location coordinates and Pose Flag : %d",pose_flag);
        rclcpp::sleep_for(500ms);

    }
}

void BotInspector::resumeInspection() {

    pose_publisher_ = this->create_publisher<BOT_POSE>("goal_pose", 10);

    std::shared_ptr<rclcpp::Node> odom_node = rclcpp::Node::make_shared("odom_node");

    auto odom_subscriber = odom_node->create_subscription<ODOMETRY>("odom", 10, std::bind(&BotInspector::resumeInspectionCallback, this , _1));
    
    BOT_POSE goal_pose_;

    goal_pose_.header.frame_id = "map";
    goal_pose_.header.stamp.sec = 0;
    goal_pose_.header.stamp.nanosec = 0;
    goal_pose_.pose.position.x = 0 ;
    goal_pose_.pose.position.y = 0;
    goal_pose_.pose.position.z = 0;
    goal_pose_.pose.orientation.x = 0;
    goal_pose_.pose.orientation.y = 0;
    goal_pose_.pose.orientation.z = 0;
    goal_pose_.pose.orientation.w = 1;

    while(!pose_flag){
        rclcpp::spin_some(odom_node);
        pose_publisher_->publish(goal_pose_);
        RCLCPP_INFO(this->get_logger(), "Publishing station coordinates and Pose Flag : %d",pose_flag);
        rclcpp::sleep_for(500ms);

    }


}

void BotInspector::inspectionCallback(const ODOMETRY::SharedPtr odom_msg_i){

    if((std::abs(static_cast<int>(odom_msg_i->pose.pose.position.x - goal_x)) == 0) && (std::abs(static_cast<int>(odom_msg_i->pose.pose.position.y + goal_y)) == 0)){
        pose_flag = true;
        RCLCPP_INFO(this->get_logger(), "Inspector reached goal position and Pose Flag : %d",pose_flag);
    }
    
}

void BotInspector::resumeInspectionCallback(const ODOMETRY::SharedPtr odom_msg_r){
    if((std::abs(static_cast<int>(odom_msg_r->pose.pose.position.x)) == 0) && (std::abs(static_cast<int>(odom_msg_r->pose.pose.position.y)) == 0)){
        pose_flag = true;

        RCLCPP_INFO(this->get_logger(), "Inspector reached station and Pose Flag : %d",pose_flag);
    }
}