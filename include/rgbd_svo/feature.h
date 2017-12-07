#ifndef RGBD_SVO_FEATURE_H
#define RGBD_SVO_FEATURE_H

#include <opencv/cv.h>

namespace rgbd_svo
{

class Feature
{
public:
  Feature(double u, double v, const cv::Mat& rgb, const cv::Mat& depth);

  const double& u() const;
  const double& v() const;
  const double& depth() const;
  const cv::Mat& patch() const;
  const cv::Mat& jacobian() const;

  double& u();
  double& v();
  double& depth();

private:
  double u_;
  double v_;
  double depth_;
  cv::Mat patch_;
  cv::Mat jacobian_;
};

} //namespace rgbd_svo

#endif // RGBD_SVO_FEATURE_H
