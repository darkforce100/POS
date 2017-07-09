//
// Created by Trenton Telge on 6/28/17.
//

#include "TaxableItem.h"


/**
 * Sets tax rate of book item instance
 *
 * @param double r tax rate of book item instance (this)
 * **/
void TaxableItem::setTaxRate(double r){
    TaxableItem::taxRate = r;
}

/**
 * Returns tax rate as percentage of taxable item instance
 *
 * @returns double tax rate of taxable item instance (this)
 * **/
double TaxableItem::getTaxRate() const {
    return TaxableItem::taxRate * 100;
}

/**
 * Returns price with tax added of taxable item instance
 *
 * @returns double taxed price of taxable item instance (this)
 * **/
double TaxableItem::getTaxedPrice() const {
    return TaxableItem::basePrice + TaxableItem::getTaxAmount();
}

/**
 * Returns tax amount of taxable item instance
 *
 * @returns double tax amount of taxable item instance (this)
 * **/
double TaxableItem::getTaxAmount() const {
    return TaxableItem::basePrice * (TaxableItem::taxRate);
}

/**
 * Returns Type of item instance
 *
 * @override
 * @virtual
 * @returns string Type of item instance (this)
 * **/
string TaxableItem::getType() const {
    return "TAXABLE";
}