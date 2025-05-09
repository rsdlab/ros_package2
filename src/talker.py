#!/usr/bin/env python3
# coding: UTF-8

import rospy
from std_msgs.msg import String
def talker():
   pub = rospy.Publisher('chatter', String, queue_size=10)
   rospy.init_node('talker')
   rate = rospy.Rate(10)
   while not rospy.is_shutdown():
       hello_str = "hello world"
       print(hello_str)
       rospy.loginfo(hello_str)
       pub.publish(hello_str)
       rate.sleep()
if __name__ == '__main__':
   try:
       talker()
   except rospy.ROSInterruptException:
       pass
