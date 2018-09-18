#include <ros/ros.h>
#include "dummy_cloud_map/Belief.h"
#include "geometry_msgs/Pose.h"

void cb_pose(const geometry_msgs::Pose::ConstPtr& msg1)
{
    printf("msg.data[0]:%f\n",msg1->position.x);
    printf("msg.data[1]:%f\n",msg1->position.y);
    printf("msg.data[2]:%f\n",msg1->position.z);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber pos_sub = nh.subscribe<geometry_msgs::Pose>
            ("/UAV_FW/B/pose", 10, cb_pose);

    ros::spin();

    return 0;
}
