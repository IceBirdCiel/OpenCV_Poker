//
// Created by hung9 on 10/02/2022.
//

#pragma once

#define _USE_MATH_DEFINES
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

#include <math.h>
#include "Card.h"
#include "SolutionBResult.h"

class MatchCards {
public:
    MatchCards()= default;
    SolutionBResult Match(cv::Mat im, std::vector<Card> data);
};
