//
// Created by hung9 on 10/02/2022.
//

#pragma once

#include <opencv2/opencv.hpp>
#include "Card.h"

class DataSetCards {
public:
    DataSetCards(){}
    void CreateData(cv::Mat im);
    void AddMask(cv::Mat &im);

    cv::Mat im;
    std::vector<Card> data;

    const std::vector<int> cardTypes = {
        14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2
    };
    const std::vector<std::string> colors = {
        "Clubs", "Spades", "Diamonds", "Hearts"
    };
};

