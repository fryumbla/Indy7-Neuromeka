[![ROS](http://www.ros.org/wp-content/uploads/2013/10/rosorg-logo1.png)](http://www.ros.org/)

<h1 style="border:none"> RISE Indy7 Neuromeka ROS Manipulation Package </h1>
&copy; 2020, Francisco Yumbla

<hr>

## 1. How to Install

### 1.1. System Requirements

This package is written an tested on **Ubuntu 18.04 + ROS Melodic** environment. Dependencies are also for this environment.

Note: the same package can work in **Ubuntu 16.04 + ROS Kinetic**

### 1.2. Dependencies Prerequisites

There are a number of dependencies in this package, since the ABB robot is operated by ROS-Industrial package. Please install all the packages listed below in your Ubuntu PC, in the given order. These packages can be installed by `apt` package manager.

* ros-melodic-desktop-full
* ros-melodic-industrial-core
* ros-melodic-industrial-msgs
* ros-melodic-industrial-robot-client
* ros-melodic-industrial-robot-simulator
* ros-melodic-industrial-utils
* ros-melodic-abb
* ros-melodic-moveit
* ros-melodic-joint-trajectory-controller

Now,Extract the metapackage `Indy7-Neuromeka` into `${ros_workspace}/src`. `catkin_make` your workspace.

**WARNING: If you planing use grippers with this robot. You need copy the gripper package https://github.com/fryumbla/Robotiq-grippers.git**


## 2. Structure of Package

* **indy7_description:** This package contains the URDF and XACRO files for a different configuration of the robot with grippers.
* **indy7_gazebo:** This package contains the URDF and XACRO files for a different configuration of the robot with grippers.
* **indy7_master:** This pasckage contains a diferrents examples of motion used MoveIt and the joystick&keyboard control of the real robot.
* **indy7_vrep:** This package contains the communication with V-REP simulator including examples and scenes
* **indy7_configuration_moveit:** This package contains the diferent MoveIt configuration of a different configuration of the robot


## 3. How to Use

### 3.1. Simulation

Open terminal and `roscore` and `Enter`. 

#### 3.1.1 Rviz Visualization

1. Launch the robot visualization Rviz
   ```
   roslaunch indy7_description indy7_display.launch
   ```
   If you need see other configuration you can space and include **gripper_2f:=true** or **gripper_3f:=true**
   ```
   roslaunch indy7_description indy7_display.launch gripper_2f:=true
   ```

2. Launch the robot with Moveit configuration
   ```
   roslaunch indy7_description indy7_moveit.launch
   ```
   If you need see other configuration you can space and include **gripper_2f:=true** or **gripper_3f:=true**
   ```
   roslaunch indy7_description indy7_moveit.launch gripper_3f:=true
   ```

#### 3.1.2 V-REP Simulation

1. V-REP execution (Since simulation is performed with vrep remote api and PLAY, roscore must be executed first): Open the scene of the indy7_vrep/scenes folder 


2. Run the step 3.1.1 visualization Rviz or MoveIt

3. Run the next node for the communication Vrep to ros
   ```
   rosrun indy7_vrep comunication
   ```
4. You can control with publish direct the Jointstates or generate other but you need change the subscribe in the **vrep_control.cpp** file

You can find a example to publish a new joint mesage:

To see the list of movement, type `rosrun indy7_vrep movement.py` program, introduce the number do you want to move `1 2 3 4 5` and `Enter`.
This node publish the joints goals in the topic `/joint_goals` or the joints states in the topic `/joint_states`

#### 3.1.2 Gazebo Simulation (in construction)

1. Launch the robot in gazebo
   ```
   roslaunch indy7_moveit_gazebo.launch

   ```

2. Run the next node for the communication ROS to Gazebo
   ```
   rosrun indy7_gazebo communitation_gazebo.py 
   ```
To see the list of movement, type `rosrun bioloid_gp_master movement.py` program, introduce the number do you want to move `1 2 3` and `Enter`.
This node publishes the joints goals in the topic `/joint_goals`

### 3.2. Real Robot

The real robot work with the moveit_configuration package for precaution collision in our workspace or environment

Setup the Robot and turn on. 

2. Launch the robot
   ```
   roslaunch indy7_description real_robot.launch robot:=true
   ```
   If you need see other configuration you change robot:=true for **gripper_2f:=true** or **gripper_3f:=true**
   ```
   roslaunch indy7_description real_robot.launch gripper_2f:=true
   ```



<!-- moveit

    para crear uno nuevo se debe anadir 
    config folder
    controllers.yaml
    joint_names.yaml
    
    se debe copiar moveit_planing_execution.launch  cambiando con la carpeta moveit correspondiente
    
    se debe cambiar en 
    indy7_moveit_controller_manager.launch
    
    ros_controlllers.yaml
    por controllers.yaml
    
    o reemplazar 
    controller_list:
  - name: ""
    action_ns: joint_trajectory_action
    type: FollowJointTrajectory
    joints: [joint0, joint1, joint2, joint3, joint4, joint5]
    en ros_controll.yaml

    
    `roslaunch indy7_description display.launch table:=true gripper:=true camera:=true`
    
    -->

