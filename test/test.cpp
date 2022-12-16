/**
 * @file test.cpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com)
 * @brief this is simple ros test fixture with simple test
 * @version 0.1
 * @date 2022-12-15
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

TEST(TaskPlanningFixture, goalPoseCheck) { ASSERT_EQ(true, true); }
