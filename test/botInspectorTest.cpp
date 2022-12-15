#include <gtest/gtest.h>
#include <stdlib.h>
#include "rclcpp/rclcpp.hpp"



#include "../include/botInspector.hpp"

class TaskNavigation : public testing::Test {
 protected:
  rclcpp::Node::SharedPtr node_;
};

TEST_F(TaskInspection, test_for_num_publishers) {
  node_ = rclcpp::Node::make_shared("test_inspection");
  auto test_pub = node_->create_publisher<std_msgs::msg::String>
                    ("inspection", 20.0);

  auto num_pub = node_->count_publishers("inspection");
  EXPECT_EQ(1, static_cast<int>(num_pub));
}