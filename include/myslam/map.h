/*
 * @Author: your name
 * @Date: 2021-02-17 17:22:26
 * @LastEditTime: 2021-02-17 21:02:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /ch9/include/myslam/map.h
 */
#ifndef MAP_H
#define MAP_H
#include "myslam/common_include.h"
#include "myslam/frame.h"
#include "myslam/mappoint.h"

namespace myslam
{
    class Map
    {
    public:
        typedef shared_ptr<Map> Ptr;
        unordered_map<unsigned long, MapPoint::Ptr> map_points_; // all landmarks
        unordered_map<unsigned long, Frame::Ptr> keyframes_;      // all key-frames

        Map(){};

        void insertKeyFrame(Frame::Ptr frame);
        void insertMapPoint(MapPoint::Ptr map_point);

    protected:
    private:
    };

} // namespace myslam

#endif