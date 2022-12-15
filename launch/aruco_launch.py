from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import TextSubstitution
from launch.substitutions import LaunchConfiguration

def generate_launch_description():

    # target_frame = DeclareLaunchArgument('target_frame', default_value = TextSubstitution(text="talk"))

    return LaunchDescription([
        Node(
            package='ros2_aruco',
            executable='aruco_node',
            name = "aruco_node"
        )
    ])