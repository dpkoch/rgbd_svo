#ifndef RGBD_SVO_CAMERA_MODEL_H
#define RGBD_SVO_CAMERA_MODEL_H

#include <opencv/cv.h>

#include <vector>

#include <rgbd_svo/feature.h>

namespace rgbd_svo
{

class CameraModel
{
public:
  set_parameters();
  cv::Mat undistort(const cv::Mat& image);
  cv::Mat undistort_points(std::vector<Feature> points_);
};

} //namespace rgbd_svo


#endif // RGBD_SVO_CAMERA_MODEL_H
