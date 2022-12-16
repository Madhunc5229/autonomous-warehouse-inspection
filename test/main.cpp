/**
 * @file beacon.cpp
 * @author Madhu Narra Chittibabu (mnarrach@umd.edu)
 * @author Koundinya Vinnakota (vkd@umd.edu)
 * @author Sharmitha Ganeshan (mnarrach@umd.edu)
 * @brief Main file to run the test cases
 * @version 0.1
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <gtest/gtest.h>
#include <rclcpp/rclcpp.hpp>
#include "../include/botInspector.hpp"

int main(int argc, char** argv) {

  rclcpp::init(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  rclcpp::shutdown();
  return result;
}
