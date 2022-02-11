//
// Created by hung9 on 10/02/2022.
//

#include "DataSetCards.h"

void DataSetCards::CreateData(cv::Mat im){
    int width = im.cols/4;
    int height = im.rows/13;

    cv::Mat card;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            card = im(cv::Rect(i* width + 5, j*height + 5, width - 5, height - 5));
            cv::Mat tmp;
            cv::cvtColor(card, tmp, cv::COLOR_BGR2GRAY);

            card = tmp;
            //AddMask(card);
            cv::resize(tmp,card,cv::Size(width*2, height*2));
            data.push_back(card);
        }
    }
}

void DataSetCards::AddMask(cv::Mat &im)
{
    cv::Point2f tl, br;
    tl.x = im.cols * 0.25;
    tl.y = im.rows * 0.25;

    br.x = im.cols - im.cols * 0.25;
    br.y = im.rows - im.rows * 0.25;

    cv::rectangle(im,tl, br, cv::Scalar(255),-1);
}
