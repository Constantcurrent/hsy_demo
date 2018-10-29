#include <iostream>
#include <fstream>
#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"receive");
    ros::NodeHandle handle;
    ros::Publisher pub=handle.advertise<std_msgs::String>("filePub",1000);
    ros::Rate loop_rate(10);
    while(ros::ok()){
      std::stringstream ss1;
      ss1<<"hello world hsy";
      std_msgs::String msg;
      msg.data=ss1.str();
      pub.publish(msg);
     // ROS_INFO("%s", msg.data.c_str());
      ros::spinOnce();
      loop_rate.sleep();
    }
    return 0;           //关闭文件输入流 n
}

