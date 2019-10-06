#include "ros/ros.h"
#include "master_ros/demo_msg.h"
#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "demo_msg_publisher");
    ros::NodeHandle node_obj;
    ros::Publisher msg_publisher = node_obj.advertise<master_ros::demo_msg>("/msg_number", 10);
    master_ros::demo_msg msg;
    ros::Rate loop_rate(10);
    msg.number = 0;
    while(ros::ok())
    {
	msg.greeting ="hello";
	ROS_INFO("%d", msg.number);
	msg_publisher.publish(msg);
	ros::spinOnce();
	loop_rate.sleep();
	++msg.number;
    }
    return 0;
}
