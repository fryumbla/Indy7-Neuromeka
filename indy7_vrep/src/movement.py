#!/usr/bin/env python

import rospy

from sensor_msgs.msg import JointState
from std_msgs.msg import Header


def main():
    

    rospy.init_node("example_move")

    while not rospy.is_shutdown():
        
        number = input ("Enter number: ")
        if (number==1):
            joint_position_state=[0.0, 0.0, 0, 0.0, 0.0, 0.0]
        if (number==2):
            joint_position_state=[0.80, 0.50, 0, 0.5, 1, 0.0]
        if (number==3):
            #parado
            joint_position_state=[0.0, 0.0, 0, 0.0, 0.0, 0.0]
        if (number==4):
            #derecha alza
            joint_position_state=[0.0, 0.5, 0, 0.5, 0.0, 0.5]		
        if (number==5):
            # primer paso
            joint_position_state=[0.0, 0.0, 0, 0.0, 0.0, 0.0]

        pub = rospy.Publisher('joint_states', JointState, queue_size=10)
        # rate = rospy.Rate(1000000) # 10hz
        joints_states = JointState()
        joints_states.header = Header()
        joints_states.header.stamp = rospy.Time.now()
        joints_states.name = ["joint0", "joint1", "joint2", "joint3", "joint4", "joint5"]
        joints_states.position = joint_position_state
        pub.publish(joints_states)
        rate = rospy.Rate(10) # 10hz   
        # rospy.sleep(5)

if __name__ == '__main__':
    main()