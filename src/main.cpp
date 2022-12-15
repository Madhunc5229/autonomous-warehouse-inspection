/**
 * @file main.cpp
 * @author Madhu Narra Chittibabu (mnarrach@umd.edu)
 * @author Koundinya Vinnakota (vkd@umd.edu)
 * @author Sharmitha Ganeshan (mnarrach@umd.edu)
 * @brief Main file to execute the bot's movements.
 * @version 0.1
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/beacon.hpp"
#include "../include/botInspector.hpp"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  BotInspector inspector;

  // Beacon beacon;

  inspector.moveToLocation();

  // std::cout<<"dne"<<"/n";
  inspector.rotateInspector();
  inspector.resumeInspection();

  rclcpp::shutdown();
}
