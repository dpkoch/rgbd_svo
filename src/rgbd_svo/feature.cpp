#include <rgbd_svo/feature.h>
#include <rgbd_svo/helpers.h>

#include <opencv2/features2d.hpp>

namespace rgbd_svo
{

std::vector<Feature> Feature::get_features(const cv::Mat &gray, const cv::Mat &depth, double fx, double fy, double u0, double v0)
{
  // assume image has been undistorted

  // create mask to only detect features with valid depth and not too close to the edge
  cv::Mat border_mask = cv::Mat::zeros(gray.rows, gray.cols, CV_8U);
  border_mask(cv::Rect(PATCH_SIZE, PATCH_SIZE, gray.cols-2*PATCH_SIZE, gray.rows-2*PATCH_SIZE)) = 1;

  cv::Mat mask = border_mask & cv::Mat(depth == depth); // (depth == depth) returns 0 if depth is NaN, 1 if depth is valid

  // extract features
  std::vector<cv::Point2f> feature_coordinates;
  cv::goodFeaturesToTrack(gray, feature_coordinates, MAX_FEATURES, 0.01, 2*PATCH_SIZE, mask);

  // compute image gradients
  cv::Mat dx;
  cv::Mat dy;
  cv::spatialGradient(gray, dx, dy);

  // populate list of features
  std::vector<Feature> features;
  for (size_t i = 0; i < feature_coordinates.size(); i++)
  {
    // store image coordinates
    Feature feature;
    feature.coordinate_ = feature_coordinates[i];

    // store depth
    feature.depth_ = depth.at<float>(feature.coordinate_);

    // compute 3D point
    feature.point_3D_.x = feature.depth_/fx * (feature.coordinate_.x - u0);
    feature.point_3D_.y = feature.depth_/fy * (feature.coordinate_.y - v0);
    feature.point_3D_.z = feature.depth_;

    // store image patch
    cv::Rect roi = cv::Rect(feature.coordinate_-cv::Point2f(PATCH_SIZE/2.0f, PATCH_SIZE/2.0f),
                            cv::Size(PATCH_SIZE, PATCH_SIZE));
    gray(roi).copyTo(feature.patch_);
    feature.patch_.reshape(0, FEATURE_VECTOR_SIZE);

    // compute Jacobian
    //! @todo compute Jacobian

    // add to list of extracted features
    features.push_back(feature);
  }

  return features;
}

} //namespace rgbd_svo
