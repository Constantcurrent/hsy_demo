#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
int main()
{
    string file="/catkin_ws/src/ORB_SLAM/KeyFrameTrajectory.txt";
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close();
    return 0;           //关闭文件输入流 n
}

