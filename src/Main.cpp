#include <iostream>

#include <opencv2/opencv.hpp>

#include "DataSetCards.h"
#include "MatchCards.h"
#include "SolutionBResult.h"

SolutionBResult compute(const cv::Mat& testImage)
{
    SolutionBResult result;

    DataSetCards set;
    cv::Mat im;
    im = cv::imread("resources/cards.jfif");
    set.CreateData(im);

    MatchCards scene;
    //cv::Mat test = cv::imread("resources/tables_poker/img.png");
    return scene.Match(testImage, set.data);
    //std::cout << "Close Project" << std::endl;
}
