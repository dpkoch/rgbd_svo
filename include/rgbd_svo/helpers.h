/**
 * @file helpers.h
 * @author Daniel Koch <daniel.koch@byu.edu>
 */

#ifndef RGBD_SVO_HELPERS_H
#define RGBD_SVO_HELPERS_H

#include <cv_bridge/cv_bridge.h>
#include <string>

namespace rgbd_svo
{

std::string image_encoding(const cv::Mat& image)
{
  std::string encoding;

  switch(image.depth())
  {
  case CV_8U:  encoding = "8U"; break;
  case CV_8S:  encoding = "8S"; break;
  case CV_16U: encoding = "16U"; break;
  case CV_16S: encoding = "16S"; break;
  case CV_32S: encoding = "32S"; break;
  case CV_32F: encoding = "32F"; break;
  case CV_64F: encoding = "64F"; break;
  default:     encoding = "User"; break;
  }

  encoding += "C";
  encoding += '0' + image.channels();

  return encoding;
}

} // namespace rgbd_svo

#endif // RGBD_SVO_HELPERS_H
