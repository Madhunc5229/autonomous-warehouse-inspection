/**
 * @file botInspector.h
 * @author Madhu Narra Chittibabu (mnarrach@umd.edu)
 * @brief This file contains all methods related to the turtle bot
 * @version 0.1
 * @date 2022-12-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INCLUDE_BOTINSPECTOR_H_
#define INCLUDE_BOTINSPECTOR_H_

#include <rclcpp/rclcpp.hpp>

/**
 * @brief This class helps in interfacing with the turtlebot
 * 
 */
class BotInspector {
    public:
        /**
         * @brief Construct a new Bot Inspector object
         * 
         */
        BotInspector();
    private:
        rclcpp::Publisher<geometry_msgs::msgs::Twist>::SharedPtr publisher_;
        std::array<double> aruco_locations;
        gemetry_msgs::Twist msg;

        /**
         * @brief this is a callback function
         * 
         */
        void inspectorCallBack();

}

#endif // INCLUDE_BOTINSPECTOR_H_