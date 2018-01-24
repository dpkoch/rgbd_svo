#ifndef RGBD_SVO_CAMERA_MODEL_H
#define RGBD_SVO_CAMERA_MODEL_H

#include <cv_bridge/cv_bridge.h>

#include <vector>

#include <rgbd_svo/feature.h>

namespace rgbd_svo
{

class CameraModel
{
public:
  void set_parameters();
  void undistort(cv::Mat& image);
  cv::Mat undistort_points(std::vector<Feature> points_);
};

} //namespace rgbd_svo


#endif // RGBD_SVO_CAMERA_MODEL_H
