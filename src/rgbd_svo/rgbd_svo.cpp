#include <rgbd_svo/rgbd_svo.h>

namespace rgbd_svo
{

RGBD_SVO::RGBD_SVO()
{
}

geometry_msgs::Transform RGBD_SVO::compute_transform(const cv::Mat& keyframe, const cv::Mat& current)
{
  std::vector<Feature> keyframe_features = extract_features(keyframe);
  return compute_transform(keyframe_features, current);
}

geometry_msgs::Transform RGBD_SVO::compute_transform(const std::vector<RGBD_SVO::Feature> &keyframe_features, const cv::Mat &current)
{
}

std::vector<RGBD_SVO::Feature> RGBD_SVO::extract_features(const cv::Mat &keyframe)
{
}

} // namespace rgbd_svo
