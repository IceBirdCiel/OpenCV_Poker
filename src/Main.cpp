#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
    cv::Mat im;
    im = cv::imread("resources/cards.jfif");

    cv::imshow("test", im);
    cv::waitKey(0);
    std::cout << "Close Project" << std::endl;
}
