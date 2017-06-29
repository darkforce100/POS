//
// Created by Trenton Telge on 6/28/17.
//

#ifndef POS_GROCERYITEM_H
#define POS_GROCERYITEM_H

#include "Item.h"

struct td_s{
    int month, day, year;
};

class GroceryItem : public Item{
protected:
    td_s expiration;
public:
    const td_s getExpiration() const;
    void setExpiration(td_s expiration);
    string getType() const;
};

#endif //POS_GROCERYITEM_H
