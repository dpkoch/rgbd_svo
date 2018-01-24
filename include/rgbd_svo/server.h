#ifndef RGBD_SVO_SERVER_H
#define RGBD_SVO_SERVER_H

#include <ros/ros.h>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>

#include <relative_nav/VOUpdate.h>
#include <relative_nav/Keyframe.h>

#include <rgbd_svo/rgbd_svo.h>
#include <rgbd_svo/feature.h>

#include <vector>

namespace rgbd_svo
{

class Server
{
public:
  Server();

private:
  void rgbd_callback(const sensor_msgs::ImageConstPtr& rgb,
                     const sensor_msgs::ImageConstPtr& depth,
                     const sensor_msgs::CameraInfoConstPtr& info);

  void initialize_keyframe(const sensor_msgs::ImageConstPtr& rgb,
                           const sensor_msgs::ImageConstPtr& depth,
                           const sensor_msgs::CameraInfoConstPtr &info);

  ros::NodeHandle nh_;
  ros::NodeHandle nh_private_;

  typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image,
                                                          sensor_msgs::Image,
                                                          sensor_msgs::CameraInfo> RGBDSyncPolicy;

  message_filters::Subscriber<sensor_msgs::Image> rgb_subscriber_;
  message_filters::Subscriber<sensor_msgs::Image> depth_subscriber_;
  message_filters::Subscriber<sensor_msgs::CameraInfo> camera_info_subscriber_;

  message_filters::Synchronizer<RGBDSyncPolicy> synchronizer_;

  ros::Publisher vo_publisher_;
  ros::Publisher keyframe_publisher_;

  ros::Publisher debug_features_publisher_;

  RGBD_SVO vo_;
  std::vector<Feature> keyframe_features_;
};

} // namespace rgbd_svo

#endif // RGBD_SVO_SERVER_H
