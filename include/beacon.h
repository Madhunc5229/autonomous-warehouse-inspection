/**
 * @file beacon.h
 * @author Madhu Narra Chittibabu (mnarrach@umd.edu)
 * @brief This file contains all methods related to the aruco markers
 * @version 0.1
 * @date 2022-12-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INCLUDE_BEACON_H_
#define INCLUDE_BEACON_H_

#include <rclcpp/rclcpp.hpp>

/**
 * @brief This class helps in interfacing with the aruco markers
 * 
 */
class Beacon {
    public:
        /**
         * @brief Construct a new Beacon object
         * 
         */
        Beacon();
    private:
        /**
         * @brief This method is used to broadcast marker position
         * 
         */
        beaconBroadcaster();
        /**
         * @brief This method is used to get transform of marker w.r.t world
         * 
         */
        beaconTransform();
        
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
        geometry_msgs::msg::TransformedStamped t;
        tf2::Quaternion q_rpy;
}

#endif // INCLUDE_BOTINSPECTOR_H_