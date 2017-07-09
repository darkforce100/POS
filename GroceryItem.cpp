//
// Created by Trenton Telge on 6/28/17.
//

#include "GroceryItem.h"

/**
 * Returns expiration date of grocery item instance
 *
 * @returns td_s expiration date of grocery item instance (this)
 * **/
const td_s GroceryItem::getExpiration() const {
    return GroceryItem::expiration;
}

/**
 * Sets expiration date of grocery item instance
 *
 * @param td_s expiration expiration date of grocery item instance (this)
 * **/
void GroceryItem::setExpiration(const td_s expiration) {
    GroceryItem::expiration = expiration;
}

/**
 * Returns Type of item instance
 *
 * @override
 * @returns string Type of item instance (this)
 * **/
string GroceryItem::getType() const {
    return "GROCERY";
}