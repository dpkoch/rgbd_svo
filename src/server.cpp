#include <boost/bind.hpp>

#include <rgbd_svo/server.h>

namespace rgbd_svo
{

Server::Server() :
  nh_(),
  nh_private_("~"),
  rgb_subscriber_(nh_, "rgb/image", 1),
  depth_subscriber_(nh_, "depth/image", 1),
  camera_info_subscriber_(nh_, "rgb/info", 1),
  time_synchronizer_(rgb_subscriber_, depth_subscriber_, camera_info_subscriber_, 10)
{
  time_synchronizer_.registerCallback(boost::bind(&Server::rgbd_callback, this, _1, _2, _3));
}

void Server::rgbd_callback(sensor_msgs::ImageConstPtr rgb,
                            sensor_msgs::ImageConstPtr depth,
                            sensor_msgs::CameraInfoConstPtr info)
{
  // convert to opencv format

  // apply calibration (initialize if needed)

  // initialize keyframe features if needed

  // compute VO

  // decide if we need a new keyframe

  // publish VO

  // if we need a new keyframe, initialize keyframe features and publish keyframe message
}

} // namespace rgbd_svo
