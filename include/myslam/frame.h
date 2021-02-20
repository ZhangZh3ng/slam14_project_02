/*
 * @Author: your name
 * @Date: 2021-02-17 09:54:08
 * @LastEditTime: 2021-02-17 21:22:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /ch9/include/myslam/frame.h
 */
#ifndef FRAME_H
#define FRAME_H
#include "myslam/common_include.h"
#include "myslam/camera.h"
namespace myslam
{
    // forward declare
    class MapPoint;
    class Frame
    {
    public:
        typedef std::shared_ptr<Frame> Ptr;
        unsigned long id_;
        double time_stamp_; // when it is recorded
        Sophus::SE3d T_c_w_; // transform from world to camera
        Camera::Ptr camera_; // Pinhole RGBD Camera model
        cv::Mat color_, depth_; // color and depth image

        Frame();
        Frame(long id, double time_stamp=0, Sophus::SE3d T_c_w=Sophus::SE3d(), Camera::Ptr camera=nullptr, cv::Mat color=cv::Mat(), cv::Mat depth=cv::Mat());
        ~Frame();

        // factory function
        static Frame::Ptr creatFrame();
        // find the depth in depth map
        double findDepth(const cv::KeyPoint& kp);
        // get camera center
        Eigen::Vector3d getCamCenter() const;
        // check if a point is in this frame
        bool isInFrame(const Eigen::Vector3d &pt_world);

    protected:
    private:
    };
}

#endif