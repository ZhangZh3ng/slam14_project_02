/*
 * @Author: your name
 * @Date: 2021-02-17 16:29:27
 * @LastEditTime: 2021-02-18 16:02:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /ch9/include/myslam/visual_odometry.h
 */
#ifndef VISUAL_ODOMETRY_H
#define VISAUL_ODOMETRY_H

#include "myslam/common_include.h"
#include "myslam/map.h"
#include <opencv2/features2d/features2d.hpp>

namespace myslam
{
    class VisualOdometry
    {
    public:
        typedef shared_ptr<VisualOdometry> Ptr;
        enum VOState
        {
            INITIALIZING = -1,
            OK = 0,
            LOST
        };

        VOState state_;   // current VO state
        Map::Ptr map_;    // map with all frames and map points
        Frame::Ptr ref_;  // reference frame
        Frame::Ptr curr_; // current frame

        cv::Ptr<cv::ORB> orb_;                // orb detector and computer
        vector<cv::Point3f> pts_3d_ref_;       // 3d points in reference frame
        vector<cv::KeyPoint> keypoints_curr_; // keypoints in current frame
        cv::Mat descriptors_curr_;            // descriptor in current frame
        cv::Mat descriptros_ref_;             // descriptor in reference frame
        vector<cv::DMatch> feature_matches_;

        Sophus::SE3d T_c_r_estimated_; // the estimated pose of current frame
        int num_inliers_;              // number of inlier features in icp
        int num_lost_;                 // number of lost times

        // parameters
        int num_of_features_; // number of features
        double scale_factor_; // scale in image pyramid
        int level_pyramid_;   // number of pyramid levels
        float match_ratio_;   // ratio for selecting good matches
        int max_num_lost_;    // max number of continuous lost times
        int min_inliers_;     // minimum inliers

        double key_frame_min_rot;   // minimal rotation of two key-frames
        double key_frame_min_trans; // minimal translation of two key-frames

        // public function
        VisualOdometry();
        ~VisualOdometry();

        bool addFrame(Frame::Ptr frame); // add a new frame

    protected:
        // inner operation
        void extractKeyPoints();
        void computeDescriptors();
        void featureMatching();
        void poseEstimationPnP();
        void setRef3DPoints();

        void addKeyFrame();
        bool checkEstimatedPose();
        bool checkKeyFrame();

    private:
    };
}

#endif