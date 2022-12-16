/**
 * @file beacon.cpp
 * @author Madhu Narra Chittibabu (mnarrach@umd.edu)
 * @author Koundinya Vinnakota (vkd@umd.edu)
 * @author Sharmitha Ganeshan (mnarrach@umd.edu)
 * @brief Testting the cpp files.
 * @version 0.1
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <gtest/gtest.h>
#include <stdlib.h>

#include <chrono>
#include <cstdlib>
#include <rclcpp/rclcpp.hpp>


class TaskPlanningFixture : public testing::Test {
 public:
  TaskPlanningFixture() : node_(std::make_shared<rclcpp::Node>("basic_test")) {
    RCLCPP_ERROR_STREAM(node_->get_logger(), "DONE WITH CONSTRUCTOR!!");
  }

  void SetUp() override {
    // Setup things that should occur before every test instance should go here
    RCLCPP_ERROR_STREAM(node_->get_logger(), "DONE WITH SETUP!!");
  }

  void TearDown() override { std::cout << "DONE WITH TEARDOWN" << std::endl; }

 protected:
  rclcpp::Node::SharedPtr node_;
};

TEST(TaskPlanningFixture, goalPoseCheck) {
  ASSERT_EQ(true, true);
}
