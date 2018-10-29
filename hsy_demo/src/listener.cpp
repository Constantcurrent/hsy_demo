#include "stdio.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
void chatterCallback(const std_msgs::String::ConstPtr& msg){
     ROS_INFO("I got:[%s]",msg->data.c_str());

}

int main(int argc,char **argv){
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub=n.subscribe("filePub",1000,chatterCallback);
    ros::spin();//第一次操作
}
