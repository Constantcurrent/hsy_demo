#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include<ros/ros.h>
#include<std_msgs/String.h>
#include<sstream>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"readFile");
    ros::NodeHandle handle;
    ros::Publisher pub=handle.advertise<std_msgs::String>("filePub",1000);
    ros::Rate loop_rate(10);
    int count=0;
    while(ros::ok()){
       std_msgs::String msg;
       std::stringstream ss;
       std::string file="/catkin_ws/src/ORB_SLAM/KeyFrameTrajectory.txt";
       std::ifstream infile;
       infile.open(file.data());   //将文件流对象与文件连接起来 
       assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
       std::string s;
       while(getline(infile,s))
      {
        ss<<s<<"/";
       }
      msg.data=ss.str();
      pub.publish(msg);
     // ROS_INFO("%s", msg.data.c_str());
      ros::spinOnce();
      loop_rate.sleep();
      ++count;
      infile.close();
    }
    return 0;           //关闭文件输入流 n
}

