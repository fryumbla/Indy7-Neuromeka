#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseArray.h>
#include <iostream> 
  
using namespace std;

geometry_msgs::PoseArray pos_connectors;


int main(int argc, char **argv)
{
  ros::init(argc, argv, "example_movement");
  ros::NodeHandle node_handle;  
  ros::AsyncSpinner spinner(2);
  spinner.start();

  // ros::waitForShutdown();

  moveit::planning_interface::MoveGroupInterface group("indy7");
  // We can print the name of the reference frame for this robot.
  ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
  
  // We can also print the name of the end-effector link for this group.
  ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());


  geometry_msgs::Pose home_camera;

  // position in x y z direction
  home_camera.position.x = 0.5;
  home_camera.position.y = 0;
  home_camera.position.z = 0.50;
  home_camera.orientation.w = 0;
  home_camera.orientation.x = -0.7071068;
  home_camera.orientation.y = 0.7071068;
  home_camera.orientation.z = 0;
  group.setPoseTarget(home_camera);

  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  moveit::planning_interface::MoveItErrorCode success = group.plan(my_plan); 
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success.val ? "":"FAILED"); 
  group.execute(my_plan);
  // group.move();
  sleep(5.0);

  return 0;
}



