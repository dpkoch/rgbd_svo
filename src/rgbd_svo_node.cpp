#include <ros/ros.h>
#include <rgbd_svo/server.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "rgbd_svo");

  rgbd_svo::Server server;
  ros::spin();

  return 0;
}
