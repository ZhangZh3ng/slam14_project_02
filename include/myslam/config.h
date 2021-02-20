/*
 * @Author: your name
 * @Date: 2021-02-17 16:28:54
 * @LastEditTime: 2021-02-17 16:42:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /ch9/include/myslam/config.h
 */
#ifndef CONFIG_H
#define CONFIG_H
#include "myslam/common_include.h"

namespace myslam
{
    class Config
    {
    public:
        ~Config(); // close the file when deconstructing
        // set a new config file
        static void setParameterFile(const std::string &fileneme);
        // access the parameter values
        template <typename T>
        static T get(const std::string &key)
        {
            return T(Config::config_->file_[key]);
        }

    protected:
    private:
        static std::shared_ptr<Config> config_;
        cv::FileStorage file_;
        Config(){}; // private constructor makes a singleton
    };
}

#endif