/*
 * @Author: your name
 * @Date: 2021-02-17 17:24:09
 * @LastEditTime: 2021-02-17 17:32:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /ch9/include/myslam/mappoint.h
 */
#ifndef MAPPOINT_H
#define MAPPOINT_H
#include "myslam/common_include.h"
namespace myslam
{
    class Frame;
    class MapPoint
    {
    public:
        typedef shared_ptr<MapPoint> Ptr;
        unsigned long id_;
        Eigen::Vector3d pos_;  // position in world
        Eigen::Vector3d norm_; // normal of viewing direction
        cv::Mat descriptor_;   // descriptor for matching
        int observed_times_;   // being observed by feature matching algo
        int matched_times_;    // being an inliner in pose estimation

        MapPoint();
        MapPoint(unsigned long id, Eigen::Vector3d position, Eigen::Vector3d norm);

        // factory function
        static MapPoint::Ptr createMapPoint();

    protected:
    private:
    };
} // namespace myslam

#endif