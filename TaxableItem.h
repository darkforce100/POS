//
// Created by Trenton Telge on 6/28/17.
//

#ifndef POS_TAXABLEITEM_H
#define POS_TAXABLEITEM_H

#include "Item.h"

class TaxableItem: public Item{
protected:
    double taxRate;
public:
    void setTaxRate(double);
    double getTaxRate() const;
    double getTaxedPrice() const;
    double getTaxAmount() const;
    virtual string getType() const;
};

#endif //POS_TAXABLEITEM_H
