# Trajectory_saving_for_SLAM
This is a project to timely export the trajectory in a SLAM project to a .txt file in TUM format.
## 1.Prerequisites
Ubuntu 64-bit 18.04 or 20.04. ROS Melodic or Noetic. [ROS Installation](http://wiki.ros.org/ROS/Installation)
## 2.Code changes to fit your SLAM
Because the coordinate system naming of the SLAM system may be different, this needs to be changed.<br>
<br>
trajectorysave.cpp lines 26 and 28 ：<br>

```
listener.waitForTransform("/camera_init", "/aft_mapped", ros::Time(0), ros::Duration(1));
listener.lookupTransform("/camera_init", "/aft_mapped", ros::Time(0), transform);
```

Change `"/camera_init" `and `"/aft_mapped"` to the new coordinate system.<br>
1. You can view the coordinate system of the current SLAM system through the following command：
```
rosrun rqt_tf_tree rqt_tf_tree
```

<div align="center">
  <img src="https://github.com/Zjj587/Trajectory_saving_for_SLAM/blob/main/tftree.png" width="600px" alt="M3DGR Logo">
</div>
2. If you see the tftree as shown above,change the code as:

```
listener.waitForTransform("/map", "/base_link", ros::Time(0), ros::Duration(1));
listener.lookupTransform("/map", "/base_link", ros::Time(0), transform);
```

## 3.Compile
Clone the repository and catkin_make:
```
git clone https://github.com/Zjj587/Trajectory_saving_for_SLAM.git
cd Trajectory_saving_for_SLAM
catkin_make
source devel/setup.bash && rosrun test_pkg save_traj_as_tum
```
## 4.Example
To run Example, you need to install and configure [Point-LIO](https://github.com/hku-mars/Point-LIO) and [evo](https://github.com/MichaelGrupp/evo). And no need to change the code.
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
![trajectorysave](https://github.com/Zjj587/Trajectory_saving_for_SLAM/blob/main/test_pkg/image/tra-point-lio-1.png)
