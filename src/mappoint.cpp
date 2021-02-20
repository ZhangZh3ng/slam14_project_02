/*
 * @Author: your name
 * @Date: 2021-02-17 17:40:18
 * @LastEditTime: 2021-02-17 20:57:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /ch9/src/mappoint.cpp
 */
#include "myslam/common_include.h"
#include "myslam/mappoint.h"

namespace myslam
{
    MapPoint::MapPoint()
    {
        id_ = -1;
        pos_ = Eigen::Vector3d(0, 0, 0);
        norm_ = Eigen::Vector3d(0, 0, 0);
        observed_times_ = 0;
    }

    MapPoint::MapPoint(unsigned long id, Eigen::Vector3d position, Eigen::Vector3d norm)
    {
        id_ = id;
        pos_ = position;
        norm_ = norm;
        observed_times_ = 0;
    }

    MapPoint::Ptr MapPoint::createMapPoint()
    {
        static long factory_id = 0;
        return MapPoint::Ptr(
            new MapPoint(factory_id++, Eigen::Vector3d(0,0,0), Eigen::Vector3d(0, 0, 0))
            );
    }

}