// Created by Quentin Pamart on 15/02/2022.

#ifndef OPENCV_POKER_CARD_H
#define OPENCV_POKER_CARD_H

#include <string>
#include <opencv2/core/mat.hpp>
#include <map>

class Card{
public:
    cv::Mat data;
    int cardType;
    std::string cardColor;
    Card(cv::Mat dataP, int type, std::string color);
    std::string ResolveCardName();

    const std::map<int, std::string> cardNames = {
            {11, "Valet"},
            {12, "Reine"},
            {13, "Roi"},
            {14, "As"},
    };
};


#endif //OPENCV_POKER_CARD_H
