#pragma once

#include "Card.h"
#include <utility>
#include <vector>

struct CardInImage{
    Card card;
    std::vector<cv::Point2f> positions;

    CardInImage(Card cardP, std::vector<cv::Point2f> positionsP) : card(std::move(cardP)), positions(std::move(positionsP)){

    }
};

class SolutionBResult {
public:
    std::vector<CardInImage> cardsInImage;
};