# Trajectory_saving_for_SLAM
This is a project to timely export the trajectory in a SLAM project to a .txt file in TUM format.
## 1.Prerequisites
Ubuntu 64-bit 18.04 or 20.04. ROS Melodic or Noetic. [ROS Installation](http://wiki.ros.org/ROS/Installation)
## 2.Code changes to fit your SLAM
Because the coordinate system naming of the SLAM system may be different, this needs to be changed.<br>
<br>
trajectorysave.cpp lines 26 and 28 ：<br>
Change `"/camera_init" `and `"/aft_mapped"` to the new coordinate system.<br>
You can view the coordinate system of the current SLAM system through the following command：
```
rosrun rqt_tf_tree rqt_tf_tree
```
## 3.Build
Clone the repository and catkin_make:
```
    cd ~/save_traj/src
    git clone https://github.com/Zjj587/Trajectory_saving_for_SLAM.git
    cd ../
    catkin_make
    source devel/setup.bash
```
## 4.Example
To run Example, you need to install and configure [Point-LIO](https://github.com/hku-mars/Point-LIO) and [evo](https://github.com/MichaelGrupp/evo).And no need to change the code.
```
# termianl 1: run Foint-LIO
roslaunch point_lio mapping_avia.launch

# terminal 2: run save_traj_as_tum
rosrun test_pkg save_traj_as_tum

# terminal 3: play data
rosbag play yourbag.bag
```
After running:
```
cd ~/save_traj
evo_traj tum test.txt -p
```

