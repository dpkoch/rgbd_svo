#include <boost/bind.hpp>

#include <rgbd_svo/server.h>

namespace rgbd_svo
{

Server::Server() :
  nh_(),
  nh_private_("~"),
  rgb_subscriber_(nh_, "/camera/rgb/image_raw", 1),
  depth_subscriber_(nh_, "/camera/depth_registered/image_raw", 1),
  camera_info_subscriber_(nh_, "/camera/rgb/camera_info", 1),
  synchronizer_(RGBDSyncPolicy(10), rgb_subscriber_, depth_subscriber_, camera_info_subscriber_)
{
  synchronizer_.registerCallback(boost::bind(&Server::rgbd_callback, this, _1, _2, _3));

  debug_features_publisher_ = nh_.advertise<sensor_msgs::Image>("features", 1);
}

void Server::rgbd_callback(const sensor_msgs::ImageConstPtr &rgb,
                           const sensor_msgs::ImageConstPtr &depth,
                           const sensor_msgs::CameraInfoConstPtr &info)
{

  // initialize calibration if needed

  // initialize keyframe features if needed
  initialize_keyframe(rgb, depth, info);

  // compute VO

  // decide if we need a new keyframe

  // publish VO

  // if we need a new keyframe, initialize keyframe features and publish keyframe message
}

void Server::initialize_keyframe(const sensor_msgs::ImageConstPtr &rgb,
                                 const sensor_msgs::ImageConstPtr &depth,
                                 const sensor_msgs::CameraInfoConstPtr &info)
{
  keyframe_features_ = vo_.extract_features(rgb, depth, info, false);

  if (debug_features_publisher_.getNumSubscribers() > 0)
  {
    cv_bridge::CvImagePtr features_img_ptr = cv_bridge::toCvCopy(rgb);
    for (size_t i = 0; i < keyframe_features_.size(); i++)
    {
      cv::circle(features_img_ptr->image, keyframe_features_[i].coordinate(), 1, CV_RGB(0,0,255));
      cv::rectangle(features_img_ptr->image, cv::Rect(keyframe_features_[i].coordinate()-cv::Point2f(2.0f,2.0f), cv::Size(4, 4)), CV_RGB(255,0,0));
    }

    debug_features_publisher_.publish(features_img_ptr->toImageMsg());
  }

  // publish keyframe message
}

} // namespace rgbd_svo
