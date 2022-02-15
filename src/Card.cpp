// Created by Quentin Pamart on 15/02/2022.

#include "Card.h"

#include <utility>

std::string Card::ResolveCardName() {
    if(cardType >= 2 && cardType <= 10){
        return std::to_string(cardType) + " " + cardColor;
    }
    else return cardNames.at(cardType) + " " + cardColor;
}

Card::Card(cv::Mat dataP, int type, std::string color) : data(std::move(dataP)), cardType(type), cardColor(std::move(color)) {

}
