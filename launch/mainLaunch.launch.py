import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.actions import ExecuteProcess, SetEnvironmentVariable
from launch_ros.actions import Node

def generate_launch_description():
    TURTLEBOT3_MODEL = os.environ['TURTLEBOT3_MODEL']
    launch_file_dir = os.path.join(get_package_share_directory('turtlebot3_gazebo'), 'launch')
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')
    # nav2_tb3 = get_package_share_directory('turtlebot3_navigation2')
    nav2_tb3 = get_package_share_directory('nav2_bringup')
    map_dir = os.path.join(get_package_share_directory('test_project'), 'maps','map_mini.yaml')
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    x_pose = LaunchConfiguration('x_pose', default='0.0')
    y_pose = LaunchConfiguration('y_pose', default='0.0')
    aruco_id = LaunchConfiguration('aruco_id')
    world = os.path.join(
        get_package_share_directory('test_project'),
        'worlds',
        'warehouse_mini.world'
    )

    declare_aruco_cmd = DeclareLaunchArgument(
        'aruco_id',
        default_value='0',
        description='ID for the aruco fiducial marker')

    start_aruco_detection_node_cmd = Node(
        package='ros2_aruco',
        executable='aruco_node',
        output='screen')

    gzserver_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzserver.launch.py')
        ),
        launch_arguments={'world': world}.items()
    )

    gzclient_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzclient.launch.py')
        )
    )

    robot_state_publisher_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_file_dir, 'robot_state_publisher.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    spawn_turtlebot_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_file_dir, 'spawn_turtlebot3.launch.py')
        ),
        launch_arguments={
            'x_pose': x_pose,
            'y_pose': y_pose
        }.items()
    )
    nav_launch = IncludeLaunchDescription(PythonLaunchDescriptionSource([
                nav2_tb3 + '/launch/bringup_launch.py']),
                launch_arguments={'map': map_dir,'params_file':nav2_tb3 + '/params/nav2_params.yaml','use_sim_time': use_sim_time}.items())

    initial_pose_pub = ExecuteProcess(
        cmd=[
            'ros2', 'topic pub -1', '/initialpose', 'geometry_msgs/PoseWithCovarianceStamped', '"{ header: {stamp: {sec: 0, nanosec: 0}, frame_id: "map"}, pose: { pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, } }"' 
        ],
        shell=True
        )

    # print(nav2_tb3 + '/navigation_custom.launch.py')
    ld = LaunchDescription()

    # Add the commands to the launch description
    ld.add_action(gzserver_cmd)
    ld.add_action(gzclient_cmd)
    ld.add_action(robot_state_publisher_cmd)
    ld.add_action(spawn_turtlebot_cmd)
    ld.add_action(nav_launch)
    ld.add_action(initial_pose_pub)


    return ld


