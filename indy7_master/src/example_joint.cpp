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

  std::vector<double> joint_group_positions;
  joint_group_positions={0, 0, -3.1416/2, 0, -3.1416/2,-3.1416/2};

  group.setJointValueTarget(joint_group_positions);

  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  moveit::planning_interface::MoveItErrorCode success = group.plan(my_plan); 
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success.val ? "":"FAILED"); 
  group.execute(my_plan);

  sleep(5.0);
  return 0;
}



