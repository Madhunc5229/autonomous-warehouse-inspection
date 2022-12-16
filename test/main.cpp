/**
 * @file main.cpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com)
 * @brief this is a main file to run all tests
 * @version 0.1
 * @date 2022-12-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <gtest/gtest.h>

#include <rclcpp/rclcpp.hpp>

#include "../include/botInspector.hpp"

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();

  rclcpp::shutdown();
  return result;
}
