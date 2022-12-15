[![Build](https://github.com/Madhunc5229/autonomous-warehouse-inspection/actions/workflows/ros_build.yml/badge.svg)](https://github.com/Madhunc5229/autonomous-warehouse-inspection/actions/workflows/ros_build.yml)
[![Coverage Status](https://coveralls.io/repos/github/Madhunc5229/autonomous-warehouse-inspection/badge.svg?branch=main)](https://coveralls.io/github/Madhunc5229/autonomous-warehouse-inspection?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
# autonomous-warehouse-inspection  
## Authors
Sprint 1 -
 - [Madhu Narra Chittibabu](https://www.linkedin.com/in/madhunc/) (Driver) (UID: 118206196)
 - [Sharmitha Ganesan](https://github.com/sharmithag) (Design Keeper) (UID: 117518931)
 - [Koundinya Vinnakota](https://github.com/koundinyavinnakota) (Navigator) (UID: 118239811)

Sprint 2 -
 - [Madhu Narra Chittibabu](https://www.linkedin.com/in/madhunc/) (Navigator) (UID: 118206196)
 - [Sharmitha Ganesan](https://github.com/sharmithag) (Design Keeper) (UID: 117518931)
 - [Koundinya Vinnakota](https://github.com/koundinyavinnakota) (Driver) (UID: 118239811)

Sprint 3 -
 - [Madhu Narra Chittibabu](https://www.linkedin.com/in/madhunc/) (Navigator) (UID: 118206196)
 - [Sharmitha Ganesan](https://github.com/sharmithag) (Design Keeper) (UID: 117518931)
 - [Koundinya Vinnakota](https://github.com/koundinyavinnakota) (Driver) (UID: 118239811)

 ## Requirements
 - C++ 14++
 - Cmake min 3.8 
 - ROS 2 Humble
 
## Building the package

### source the ROS2 setup bash.
```
source /opt/ros/humble/setup.bash
```
### Clone the repository
```
cd <ros2 workspace folder>/src
git clone https://github.com/Madhunc5229/autonomous-warehouse-inspection.git
```
### Build the package using colcon
```
cd ..
colcon build --packages-select autonomous-warehouse-inspection
```

### Source the package after building
```
source install/setup.bash
```

 #### The Quad Chart for the project can be found [here](assets/quad_chart.pdf)

 #### The Proposal for the project can be found [here](assets/Proposal.pdf)
 
 #### The Spring planning notes can be found [here](https://docs.google.com/document/d/1qIElu25JZNJVtyW8FD5T3SJKS2kH1nsZAEqA6rTz8Hw)
 
 #### The Blacklog sheets for the Sprint can be found [here](https://docs.google.com/spreadsheets/d/1X7CdlP6GfEIelaqToiiKs4L1Nf4WaPwW27uZhFS1iec/edit#gid=0)
