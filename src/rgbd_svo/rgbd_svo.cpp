#include <rgbd_svo/rgbd_svo.h>
#include <rgbd_svo/feature.h>

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
                                                     const sensor_msgs::CameraInfo &info,
                                                     bool calibrate)
{
  std::vector<Feature> keyframe_features = extract_features(keyframe_rgb, keyframe_depth, info, calibrate);
  return compute_transform(keyframe_features, current_rgb, current_depth, calibrate);
}

geometry_msgs::Transform RGBD_SVO::compute_transform(sensor_msgs::ImageConstPtr keyframe_rgb,
                                                     sensor_msgs::ImageConstPtr keyframe_depth,
                                                     sensor_msgs::ImageConstPtr current_rgb,
                                                     sensor_msgs::ImageConstPtr current_depth,
                                                     sensor_msgs::CameraInfoConstPtr info,
                                                     bool calibrate)
{
  return compute_transform(*keyframe_rgb, *keyframe_depth, *current_rgb, *current_depth, *info, calibrate);
}

geometry_msgs::Transform RGBD_SVO::compute_transform(const std::vector<Feature> &keyframe_features,
                                                     const sensor_msgs::Image &current_rgb,
                                                     const sensor_msgs::Image &current_depth,
                                                     bool calibrate)
{
  // do the real work here
}

geometry_msgs::Transform RGBD_SVO::compute_transform(const std::vector<Feature> &keyframe_features,
                                                     sensor_msgs::ImageConstPtr current_rgb,
                                                     sensor_msgs::ImageConstPtr current_depth,
                                                     bool calibrate)
{
  return compute_transform(keyframe_features, *current_rgb, *current_depth, calibrate);
}

std::vector<Feature> RGBD_SVO::extract_features(const sensor_msgs::Image &rgb,
                                                const sensor_msgs::Image &depth,
                                                const sensor_msgs::CameraInfo &info,
                                                bool calibrate)
{
  cv::Mat rgb_image = cv_bridge::toCvCopy(rgb)->image;
  cv::Mat depth_image = cv_bridge::toCvCopy(depth)->image;

  cv::Mat gray_image;
  cv::cvtColor(rgb_image, gray_image, cv::COLOR_RGB2GRAY);

  double fx = info.K[0];
  double fy = info.K[4];
  double u0 = info.K[3];
  double v0 = info.K[5];

  return Feature::get_features(gray_image, depth_image, fx, fy, u0, v0);
}

std::vector<Feature> RGBD_SVO::extract_features(sensor_msgs::ImageConstPtr rgb,
                                                sensor_msgs::ImageConstPtr depth,
                                                sensor_msgs::CameraInfoConstPtr info,
                                                bool calibrate)
{
  return extract_features(*rgb, *depth, *info, calibrate);
}


} // namespace rgbd_svo
