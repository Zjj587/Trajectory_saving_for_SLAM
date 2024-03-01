#include<iostream>
#include<fstream>
#include<eigen3/Eigen/Eigen>
#include<ros/ros.h>
#include<tf/transform_listener.h>
 
using namespace std;
 
ofstream foutC;
 
 
int main(int argc, char **argv){
    //string file_name;
    //ros::param::get("file_name",file_name);
    ros::init(argc, argv, "save_traj_as_tum");
    ros::NodeHandle nh;
    
    foutC.open("./test.txt");
    tf::TransformListener listener;//在ROS中，TransformListener 用于接收和处理变换（transform）信息，它可以监听并处理来自TF库（Transform Library）的变换信息
    ros::Rate rate(20);
    while(ros::ok()){
        tf::StampedTransform transform;//表示带有时间戳的坐标变换信息
        try
        {
            //等待获取从 "/odom" 到 "/base_link" 的坐标变换信息
            listener.waitForTransform("/camera_init", "/aft_mapped", ros::Time(0), ros::Duration(1));
            //获取从 "/odom" 到 "/base_link" 的坐标变换信息，并将其存储在 transform 变量中
            listener.lookupTransform("/camera_init", "/aft_mapped", ros::Time(0), transform);
            foutC << transform.stamp_ << " ";//变换时间戳 transform.stamp_ 写入到输出流 foutC 中
            float x = transform.getOrigin().getX();
            float y = transform.getOrigin().getY();
            float z = transform.getOrigin().getZ();
            float qx = transform.getRotation().getX();
            float qy = transform.getRotation().getY();
            float qz = transform.getRotation().getZ();
            float qw = transform.getRotation().getW();
            ROS_INFO("%f %f %f %f %f %f %f",x,y,z,qx,qy,qz,qw);
            foutC << x <<" " << y << " " << z << " " << qx << " " << qy << " " << qz << " " << qw << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        rate.sleep();
    }
    foutC.close();
    return 0;
}
