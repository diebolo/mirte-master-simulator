#ifndef __MIRTE_MASTER_VELOCITY_LIMITER_H__
#define __MIRTE_MASTER_VELOCITY_LIMITER_H__

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

/// @brief A ROS NODE which limits the velocity of a twist msgs
class VelocityLimiter {
    private:
        ros::NodeHandle nh_;

        double linear_limit_;
        double angular_limit_;

        ros::Publisher vel_repub_;
        ros::Subscriber vel_sub_;

        void velocityLimiterCallback(const geometry_msgs::Twist&) const;
    
    public:
        VelocityLimiter();
};

#endif /*__MIRTE_MASTER_VELOCITY_LIMITER_H__*/
