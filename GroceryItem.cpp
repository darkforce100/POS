//
// Created by Trenton Telge on 6/28/17.
//

#include "GroceryItem.h"

const td_s GroceryItem::getExpiration() const {
    return GroceryItem::expiration;
}

void GroceryItem::setExpiration(const td_s expiration) {
    GroceryItem::expiration = expiration;
}
string GroceryItem::getType() const {
    return "GROCERY";
}