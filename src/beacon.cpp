#include "../include/beacon.h"

Beacon::Beacon() : Node("beacon"){
   auto beacon_ = this->create_subscription<ARUCO_TYPE>("aruco_markers",10, std::bind(&Beacon::arucoCallback, this , _1));
}

void Beacon::arucoCallback(const ARUCO_TYPE::SharedPtr aruco_msg){
    RCLCPP_INFO_STREAM(this->get_logger(), aruco_msg);

}

int main(){
    rclcpp::spin(std::make_shared<Beacon>());

    rclcpp::shutdown();
}