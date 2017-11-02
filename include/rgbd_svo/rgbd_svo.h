#ifndef RGBD_SVO_RGBD_SVO_H
#define RGBD_SVO_RGBD_SVO_H

#include <geometry_msgs/Transform.h>

#include <opencv/cv.h>

#include <vector>

namespace rgbd_svo
{

class RGBD_SVO
{
public:
  struct Feature
  {
    float u;
    float v;
    float Z;
    cv::Mat patch;
  };

  RGBD_SVO();
  geometry_msgs::Transform compute_transform(const cv::Mat& keyframe, const cv::Mat& current);
  geometry_msgs::Transform compute_transform(const std::vector<Feature>& keyframe_features, const cv::Mat& current);
  std::vector<Feature> extract_features(const cv::Mat& keyframe);
};

} // namespace rgbd_svo

#endif // RGBD_SVO_RGBD_SVO_H
