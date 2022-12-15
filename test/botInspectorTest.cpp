#include <gtest/gtest.h>
#include <stdlib.h>
#include <rclcpp/rclcpp.hpp>

#include "std_msgs/msg/string.hpp"

#include "../include/autonomous-warehouse-inspection/botInspector.h"

class TaskNavigation : public testing::Test {
 protected:
  rclcpp::Node::SharedPtr node_;
};

TEST_F(TaskNavigation, test_num_publishers) {
  node_ = rclcpp::Node::make_shared("test_navigation");
  auto test_pub = node_->create_publisher<std_msgs::msg::String>
                    ("navigation", 10.0);

  auto num_pub = node_->count_publishers("navigation");
  EXPECT_EQ(1, static_cast<int>(num_pub));
}