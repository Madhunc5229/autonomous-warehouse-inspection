cmake_minimum_required(VERSION 3.8)
project(autonomous-warehouse-inspection)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(launch_testing_ament_cmake REQUIRED)
find_package(ament_cmake_gtest REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(nav_msgs REQUIRED)


# below sets up code coverage and uncrustify config file location
if(COVERAGE)
  set(CMAKE_BUILD_TYPE "Debug")
  set(CMAKE_CXX_FLAGS "--coverage")
  set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE "ON")
  set(ARG_CONFIG_FILE "${PROJECT_SOURCE_DIR}/uncrustify_google_cpp_allman.cfg"
    CACHE STRING "uncrustify config file")
endif()

include_directories(include/)
#Add Executables
add_executable(inspection src/launchInspector.cpp src/botInspector.cpp)
ament_target_dependencies(inspection rclcpp rclcpp_action std_msgs geometry_msgs sensor_msgs nav_msgs)
install(TARGETS inspection DESTINATION lib/${PROJECT_NAME})

add_executable(aruco_detect src/beacon.cpp src/launchBeacon.cpp)
ament_target_dependencies(aruco_detect rclcpp rclcpp_action std_msgs geometry_msgs sensor_msgs nav_msgs)
install(TARGETS aruco_detect DESTINATION lib/${PROJECT_NAME})

set(TESTFILES
  test/test.cpp test/botInspectorTest.cpp test/main.cpp src/botInspector.cpp test/beaconTest.cpp src/beacon.cpp)
ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
ament_target_dependencies(${PROJECT_NAME}_test rclcpp std_msgs geometry_msgs nav_msgs rclcpp tf2_ros tf2)
install(TARGETS ${PROJECT_NAME}_test DESTINATION lib/${PROJECT_NAME})

#Target folders
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY worlds DESTINATION share/${PROJECT_NAME})
install(DIRECTORY maps DESTINATION share/${PROJECT_NAME})

## Install some arbitrary executables
install(PROGRAMS      # want to make the file executable (ie. chmod a+x)
  scripts/generate_coverage_report.bash
  DESTINATION lib/${PROJECT_NAME})
  
ament_export_dependencies(rosidl_default_runtime)
ament_package()
