//
// Created by Trenton Telge on 6/28/17.
//

#include "Item.h"

void Item::setBasePrice(double b)
{
    Item::basePrice = b;
}

void Item::setName(string n)
{
    Item::name = n;
}

string Item::getName() const
{
    return Item::name;
}

double Item::getBasePrice() const
{
    return Item::basePrice;
}

string Item::getType() const {
    return "UNTAXABLE";
}