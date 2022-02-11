//
// Created by hung9 on 10/02/2022.
//

#include "MatchCards.h"

bool compare(cv::DMatch a, cv::DMatch b) { return a.distance < b.distance; }

float angle(cv::Point2f a, cv::Point2f b, cv::Point2f c){
    float angle = atan2(c.y - b.y, c.x - b.x) - atan2(a.y - b.y, a.x-b.x);
    angle = angle * 180.0 / M_PI;
    if(angle < 0) return (angle + 360);
    else return angle;
}

void MatchCards::Match(cv::Mat im, std::vector<cv::Mat> data){
    cv::Mat image;
    cv::cvtColor(im, image, cv::COLOR_BGR2GRAY);

    cv::Ptr<cv::ORB> detection = cv::ORB::create(50000);

    std::vector<cv::KeyPoint> pointsIm;
    cv::Mat descriptionIm;

    detection->detect(image, pointsIm);
    detection->compute(image, pointsIm, descriptionIm);

    std::vector<std::vector<cv::DMatch>> match;
    cv::BFMatcher matcher;

    cv::Ptr<cv::ORB> detectionCard = cv::ORB::create(10000,1.2f,8,0);

    for(int i = 0; i< data.size(); i++){
        std::vector<cv::KeyPoint> pointsCard;
        cv::Mat descriptionCard;

        detectionCard->detect(data.at(i), pointsCard);
        detectionCard->compute(data.at(i), pointsCard, descriptionCard);


        matcher.knnMatch(descriptionCard, descriptionIm, match, 2);

        std::vector<cv::DMatch> matchShort;

        for(auto m : match){
            if(m[0].distance < 0.75 * m[1].distance) matchShort.push_back(m[0]);
        }

        std::vector<cv::Point2f> imagePoints;
        std::vector<cv::Point2f> cardPoints;

        for(int i = 0; i < matchShort.size(); i ++){
            imagePoints.push_back(pointsIm[matchShort.at(i).trainIdx].pt);
            cardPoints.push_back(pointsCard[matchShort.at(i).queryIdx].pt);
        }

        cv::Mat matTransform;
        if(imagePoints.size() == cardPoints.size() && imagePoints.size() >= 4) {
            matTransform = cv::findHomography(cardPoints, imagePoints, cv::RANSAC, 4);
        }

        std::vector<cv::Point2f> corners(4);
        std::vector<cv::Point2f> image_corners(4);
        corners[0] = cv::Point2f(0, 0);
        corners[1] = cv::Point2f(0, data.at(i).rows);
        corners[2] = cv::Point2f(data.at(i).cols, data.at(i).rows);
        corners[3] = cv::Point2f( data.at(i).cols,0);

        float angleUpRight;
        float angleBottomLeft;

        if (!matTransform.empty()) {
            cv::perspectiveTransform(corners, image_corners, matTransform);
            angleUpRight = angle(image_corners[0], image_corners[1], image_corners[2]);
            angleBottomLeft = angle(image_corners[2], image_corners[3], image_corners[0]);

            if (angleUpRight > 70 && angleUpRight < 110 && angleBottomLeft > 70 && angleBottomLeft < 110) {
                cv::line(im, image_corners[0], image_corners[1], cv::Scalar(0, 0, 255), 5);
                cv::line(im, image_corners[1], image_corners[2], cv::Scalar(0, 0, 255), 5);
                cv::line(im, image_corners[2], image_corners[3], cv::Scalar(0, 0, 255), 5);
                cv::line(im, image_corners[3], image_corners[0], cv::Scalar(0, 0, 255), 5);
            }
        }
/*
        cv::Mat result;
        cv::Mat resizeIm(im.cols/4, im.rows/4, im.type());
        cv::drawMatches(data.at(i), pointsCard, image, pointsIm, matchShort, result);
        cv::resize(result, resizeIm, resizeIm.size());
        cv::imshow("reconnaissance", resizeIm);
        cv::waitKey(0);
*/
        match.clear();
    }
    //cv::Mat resizeIm(im.cols/4, im.rows/4, im.type());
    //cv::resize(im, resizeIm, resizeIm.size());
    cv::imshow("reconnaissance", im);
    cv::waitKey(0);

}