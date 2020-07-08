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
* ros-kinetic-moveit

Now,Extract the metapackage `IRB120-ABB` into `${ros_workspace}/src`. `catkin_make` your workspace.


## 2. Structure of Package

To be updated...


## 3. How to Use

### 3.1. CLI Controller

Open terminal and `roscore` and `Enter`. 
Type `rosrun rise_assembler assembler_manual_controller` in another the terminal, and you will get a R-Viz to control the robot in real time.

Display

`roslaunch indy7_description display.launch table:=true gripper:=true camera:=true`




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
    -->

