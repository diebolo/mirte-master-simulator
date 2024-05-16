# mirte-master-simulator
> A package to simulate the Mirte Master Robot.

This packaged is structered as the [mirte-gazebo](https://github.com/ArendJan/mirte-gazebo/tree/rsp) Repository.

> **NOTES:**
> Use `mirte_master_description` for the simulation by launching `gazebo.launch`
> 
> `roslaunch mirte_master_description spawn_mirte_master.launch` can be used to spawn a Mirte Master in any Gazebo world.
> (The current way of doing things only allows for 1 mirte due to naming collisions)


**WARNING:** **DO NOT export a `ROS_MASTER_URI`** to a mirte IP adress, while using Gazebo. this will cause it to hang. This is because gazebo will create its own 'world' and roscore instead of using a local mirte roscore.


### What doesn't work yet:
- The arm
- The front camera (not supplied for MDP 2024)
- IMU
- Battery

### What does work
- Flag  (Optional to enable)
- LiDAR
- Depthcamera
- Sonar

## Install
Installing `catkintools` (provides `catkin build` as alternative to `catkin_make`) is helpful and recommended: (You may need to clean your workspace if you are migrating).
```
sudo apt update && sudo apt upgrade # Make sure your system is up to date.
sudo apt install python3-catkin-tools
```
If you use this from now on build with `catkin build`

Clone this in the root folder of your catkin workspace.
```
# Create the catkin_ws if it has not been created yet or use a preexisitng one
# mkdir catkin_ws/src; cd catkin_ws
cd src
git clone git@github.com:diebolo/mirte-master-simulator.git
cd mirte-master-simulator
git submodule update --init --recursive
cd ../.. # Go back to the workspace root
```
<!-- rosdep install --from-paths src --ignore-src -r -y -->
Also install [`ArendJan/mirte_ros_packages` (branch mirte_master)](https://github.com/ArendJan/mirte-ros-packages/tree/mirte-master), you may have already done that (You where asked to remove some packages we need)
To do this:
```
# be in catkin workspace root folder
cd src
git clone https://github.com/ArendJan/mirte-ros-packages.git -b mirte-master
cd ..
```
<!-- catkin config --skiplist mirte_bringup # This package will always fail to build so ignore it. -->

To finish the install do from the catkin workspace root:
```
rosdep install --from-paths src --ignore-src -r -y
# It will says astra_camera not found, which is fine
catkin config --skiplist mirte_bringup
catkin build # remove everything except the src folder
```
<!-- rosdep install --from-paths src --ignore-packages-from-source --rosdistro noetic -y -->


<!-- ## Setup notes -->
 <!-- - Use the patched version of [RidgeBack control](https://github.com/ArendJan/ridgeback/tree/melodic-devel) -->

# Contributers
- Jasper van Brakel (Integration) | Group 10
- Tyler Olson (Exporting the SOLID WORKS to URDF (with manual frame allignment)
- Jelle Woudstra (LiDAR example)
- Xavier ... (Some intial driving)
