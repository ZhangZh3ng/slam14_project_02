/*
 * @Author: your name
 * @Date: 2021-02-17 17:39:55
 * @LastEditTime: 2021-02-19 14:18:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /ch9/src/config.cpp
 */
#include "myslam/config.h"

namespace myslam
{
    void Config::setParameterFile(const std::string &filename)
    {
        if(config_ == nullptr)
        {
            config_ = shared_ptr<Config>(new Config);
        }

        static cv::FileStorage file1( filename.c_str(), cv::FileStorage::READ );
    config_->file_ = file1; // 添加了这一行

        config_->file_ = cv::FileStorage(filename.c_str(), cv::FileStorage::READ);
        if(config_->file_.isOpened() == false)
        {
            std::cerr<< "parameter file " << filename << "does not exist." << std::endl;
            config_->file_.release();
            return;
        }
    }

    Config::~Config()
    {
        if(file_.isOpened())
        {
            file_.release();
        }
    }

    shared_ptr<Config> Config::config_ = nullptr; // 这个是干嘛的？
}