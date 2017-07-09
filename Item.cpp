//
// Created by Trenton Telge on 6/28/17.
//

#include "Item.h"


/**
 * Sets base price of grocery item instance
 *
 * @param double b base price of item instance (this)
 * **/
void Item::setBasePrice(double b)
{
    Item::basePrice = b;
}

/**
 * Sets base price of grocery item instance
 *
 * @param string n name or title of item instance (this)
 * **/
void Item::setName(string n)
{
    Item::name = n;
}

/**
 * Returns name or title of item instance
 *
 * @returns string name or title of item instance (this)
 * **/
string Item::getName() const
{
    return Item::name;
}

/**
 * Returns base price of item instance
 *
 * @returns double base price of item instance (this)
 * **/
double Item::getBasePrice() const
{
    return Item::basePrice;
}

/**
 * Returns Type of item instance
 *
 * @virtual
 * @returns string Type of item instance (this)
 * **/
string Item::getType() const {
    return "UNTAXABLE";
}