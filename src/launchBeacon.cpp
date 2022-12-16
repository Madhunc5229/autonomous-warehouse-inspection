/**
 * @file launchBeacon.cpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com)
 * @brief this file starts the beacon node
 * @version 0.1
 * @date 2022-12-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/beacon.hpp"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Beacon>());
  rclcpp::shutdown();
}
