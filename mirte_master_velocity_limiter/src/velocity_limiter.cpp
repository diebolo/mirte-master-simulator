#include <bits/c++config.h>
#include <math.h>

#include <ros/ros.h>

#include <geometry_msgs/Twist.h>

#include "mirte_master_velocity_limiter/velocity_limiter.h"

VelocityLimiter::VelocityLimiter() : nh_() {
  bool param_result = ros::param::get("~linear_limit", linear_limit_);
  ROS_ASSERT_MSG(param_result, "The ~linear_limit parameter must be set.");
  param_result = ros::param::get("~angular_limit", angular_limit_);
  ROS_ASSERT_MSG(param_result, "The ~angular_limit parameter must be set.");

  vel_repub_ = nh_.advertise<geometry_msgs::Twist>(
      "mobile_base_controller/cmd_vel_corrected", 10);
  vel_sub_ = nh_.subscribe("mobile_base_controller/cmd_vel", 10,
                           &VelocityLimiter::velocityLimiterCallback, this);
}

void VelocityLimiter::velocityLimiterCallback(
    const geometry_msgs::Twist &org_msg) const {
  double lin_mag = sqrt(org_msg.linear.x * org_msg.linear.x +
                        org_msg.linear.y * org_msg.linear.y +
                        org_msg.linear.z * org_msg.linear.z);

  double ang_mag = sqrt(org_msg.angular.x * org_msg.angular.x +
                        org_msg.angular.y * org_msg.angular.y +
                        org_msg.angular.z * org_msg.angular.z);

  geometry_msgs::Twist new_msg;

  if (lin_mag > 0.0) {
    new_msg.linear.x = org_msg.linear.x * linear_limit_ / lin_mag;
    new_msg.linear.y = org_msg.linear.y * linear_limit_ / lin_mag;
    new_msg.linear.z = org_msg.linear.z * linear_limit_ / lin_mag;
  }

  if (ang_mag > 0.0) {
    new_msg.angular.x = org_msg.angular.x * angular_limit_ / ang_mag;
    new_msg.angular.y = org_msg.angular.y * angular_limit_ / ang_mag;
    new_msg.angular.z = org_msg.angular.z * angular_limit_ / ang_mag;
  }

  vel_repub_.publish(new_msg);
}
