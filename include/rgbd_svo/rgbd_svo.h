#ifndef RGBD_SVO_RGBD_SVO_H
#define RGBD_SVO_RGBD_SVO_H

#include <geometry_msgs/Transform.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/Image.h>

#include <cv_bridge/cv_bridge.h>

#include <vector>

#include <rgbd_svo/feature.h>

namespace rgbd_svo
{

class RGBD_SVO
{
public:
  RGBD_SVO();

  void set_calibration_parameters(const sensor_msgs::CameraInfo& rgb_info, const sensor_msgs::CameraInfo& depth_info);
  void set_calibration_parameters(sensor_msgs::CameraInfoConstPtr rgb_info, sensor_msgs::CameraInfoConstPtr depth_info);

  geometry_msgs::Transform compute_transform(const sensor_msgs::Image& keyframe_rgb,
                                             const sensor_msgs::Image& keyframe_depth,
                                             const sensor_msgs::Image& current_rgb,
                                             const sensor_msgs::Image& current_depth,
                                             const sensor_msgs::CameraInfo &info,
                                             bool calibrate = true);

  geometry_msgs::Transform compute_transform(sensor_msgs::ImageConstPtr keyframe_rgb,
                                             sensor_msgs::ImageConstPtr keyframe_depth,
                                             sensor_msgs::ImageConstPtr current_rgb,
                                             sensor_msgs::ImageConstPtr current_depth,
                                             sensor_msgs::CameraInfoConstPtr info,
                                             bool calibrate = true);

  geometry_msgs::Transform compute_transform(const std::vector<Feature>& keyframe_features,
                                             const sensor_msgs::Image& current_rgb,
                                             const sensor_msgs::Image& current_depth,
                                             bool calibrate = true);

  geometry_msgs::Transform compute_transform(const std::vector<Feature>& keyframe_features,
                                             sensor_msgs::ImageConstPtr current_rgb,
                                             sensor_msgs::ImageConstPtr current_depth,
                                             bool calibrate = true);

  std::vector<Feature> extract_features(const sensor_msgs::Image& rgb,
                                        const sensor_msgs::Image& depth,
                                        const sensor_msgs::CameraInfo &info,
                                        bool calibrate = true);

  std::vector<Feature> extract_features(sensor_msgs::ImageConstPtr rgb,
                                        sensor_msgs::ImageConstPtr depth,
                                        sensor_msgs::CameraInfoConstPtr info,
                                        bool calibrate = true);
};

} // namespace rgbd_svo

#endif // RGBD_SVO_RGBD_SVO_H
