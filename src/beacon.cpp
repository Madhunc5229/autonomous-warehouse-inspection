/**
 * @file beacon.cpp
 * @author Madhu Narra Chittibabu (mnarrach@umd.edu)
 * @author Koundinya Vinnakota (vkd@umd.edu)
 * @author Sharmitha Ganeshan (mnarrach@umd.edu)
 * @brief This file contains subscriber to Aruco marker.
 * @version 0.1
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/beacon.hpp"

Beacon::Beacon() : Node("beacon") {
  auto beacon_ = this->create_subscription<ARUCO_TYPE>(
      "aruco_markers", 10, std::bind(&Beacon::arucoCallback, this, _1));
}

void Beacon::arucoCallback(const ARUCO_TYPE::SharedPtr aruco_msg) {
  RCLCPP_INFO_STREAM(this->get_logger(), aruco_msg);
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv) ;
  rclcpp::spin(std::make_shared<Beacon>());

  rclcpp::shutdown();
}
