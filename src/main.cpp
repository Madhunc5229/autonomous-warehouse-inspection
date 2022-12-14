#include "../include/botInspector.h"
#include "../include/beacon.h"

int main(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    BotInspector inspector;
    // Beacon beacon;

    inspector.moveToLocation();
    inspector.resumeInspection();

    rclcpp::shutdown();
    
}






