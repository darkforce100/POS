//
// Created by Trenton Telge on 6/28/17.
//

#include "TaxableItem.h"

void TaxableItem::setTaxRate(double r){
    TaxableItem::taxRate = r/100;
}

double TaxableItem::getTaxRate() const {
    return TaxableItem::taxRate;
}

double TaxableItem::getTaxedPrice() const {
    return TaxableItem::basePrice + TaxableItem::getTaxAmount();
}

double TaxableItem::getTaxAmount() const {
    return TaxableItem::basePrice * TaxableItem::taxRate;
}
string TaxableItem::getType() const {
    return "TAXABLE";
}