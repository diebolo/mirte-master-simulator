#include <ros/ros.h>

#include "mirte_master_velocity_limiter/velocity_limiter.h"

int main(int argc, char** argv)
{
  // Initialize the ROS Node
  ros::init(argc, argv, "velocity_limiter_node");

  VelocityLimiter vl;

  ros::spin();

  return 0;
}
