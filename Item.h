//
// Created by Trenton Telge on 6/28/17.
//
#include <string>
using namespace std;

#ifndef POS_ITEM_H
#define POS_ITEM_H

class Item{
protected:
    string name;
    double basePrice;
public:
    void setBasePrice(double);
    void setName(string);
    string getName() const;
    double getBasePrice() const;
    virtual string getType() const;
};

#endif //POS_ITEM_H
