//
// Created by hung9 on 10/02/2022.
//

#pragma once

#include <opencv2/opencv.hpp>

class DataSetCards {
public:
    DataSetCards(){}
    void CreateData(cv::Mat im);
    void AddMask(cv::Mat &im);

    cv::Mat im;
    std::vector<cv::Mat> data;
};

