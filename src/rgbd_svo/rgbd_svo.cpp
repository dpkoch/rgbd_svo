#include <rgbd_svo/rgbd_svo.h>

namespace rgbd_svo
{

RGBD_SVO::RGBD_SVO()
{
}

void RGBD_SVO::set_calibration_parameters(const sensor_msgs::CameraInfo &rgb_info,
                                          const sensor_msgs::CameraInfo &depth_info)
{
  // do the real work here
}

void RGBD_SVO::set_calibration_parameters(sensor_msgs::CameraInfoConstPtr rgb_info,
                                          sensor_msgs::CameraInfoConstPtr depth_info)
{
  set_calibration_parameters(*rgb_info, *depth_info);
}

geometry_msgs::Transform RGBD_SVO::compute_transform(const sensor_msgs::Image &keyframe_rgb,
                                                     const sensor_msgs::Image &keyframe_depth,
                                                     const sensor_msgs::Image &current_rgb,
                                                     const sensor_msgs::Image &current_depth,
                                                     bool calibrate)
{
  std::vector<Feature> keyframe_features = extract_features(keyframe_rgb, keyframe_depth, calibrate);
  return compute_transform(keyframe_features, current_rgb, current_depth, calibrate);
}

geometry_msgs::Transform RGBD_SVO::compute_transform(sensor_msgs::ImageConstPtr keyframe_rgb,
                                                     sensor_msgs::ImageConstPtr keyframe_depth,
                                                     sensor_msgs::ImageConstPtr current_rgb,
                                                     sensor_msgs::ImageConstPtr current_depth,
                                                     bool calibrate)
{
  return compute_transform(*keyframe_rgb, *keyframe_depth, *current_rgb, *current_depth, calibrate);
}

geometry_msgs::Transform RGBD_SVO::compute_transform(const std::vector<RGBD_SVO::Feature> &keyframe_features,
                                                     const sensor_msgs::Image &current_rgb,
                                                     const sensor_msgs::Image &current_depth,
                                                     bool calibrate)
{
  // do the real work here
}

geometry_msgs::Transform RGBD_SVO::compute_transform(const std::vector<RGBD_SVO::Feature> &keyframe_features,
                                                     sensor_msgs::ImageConstPtr current_rgb,
                                                     sensor_msgs::ImageConstPtr current_depth,
                                                     bool calibrate)
{
  return compute_transform(keyframe_features, *current_rgb, *current_depth, calibrate);
}

std::vector<RGBD_SVO::Feature> RGBD_SVO::extract_features(const sensor_msgs::Image &rgb,
                                                          const sensor_msgs::Image &depth,
                                                          bool calibrate)
{
  // do the real work here
}

std::vector<RGBD_SVO::Feature> RGBD_SVO::extract_features(sensor_msgs::ImageConstPtr rgb,
                                                          sensor_msgs::ImageConstPtr depth,
                                                          bool calibrate)
{
  return extract_features(*rgb, *depth, calibrate);
}


} // namespace rgbd_svo
