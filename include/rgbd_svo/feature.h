#ifndef RGBD_SVO_FEATURE_H
#define RGBD_SVO_FEATURE_H

#include <cv_bridge/cv_bridge.h>

#include <vector>

namespace rgbd_svo
{

class Feature
{
public:
  static std::vector<Feature> get_features(const cv::Mat& gray, const cv::Mat& depth, double fx, double fy, double u0, double v0);

public:
  const cv::Point2f& coordinate() const { return coordinate_; }
  const cv::Point3d& point_3D() const { return point_3D_; }
  double depth() const { return depth_; }
  const cv::Mat& patch() const { return patch_; }
  const cv::Mat& jacobian() const { return jacobian_; }

private:
  static constexpr int MAX_FEATURES = 200;
  static constexpr int PATCH_SIZE = 4;
  static constexpr int FEATURE_VECTOR_SIZE = PATCH_SIZE*PATCH_SIZE;

  cv::Point2f coordinate_;
  cv::Point3d point_3D_;
  double depth_;

  cv::Mat patch_;
  cv::Mat jacobian_;
};

} //namespace rgbd_svo

#endif // RGBD_SVO_FEATURE_H
