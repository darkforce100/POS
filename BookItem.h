//
// Created by Trenton Telge on 6/28/17.
//

#ifndef POS_BOOKITEM_H
#define POS_BOOKITEM_H

#include "TaxableItem.h"

class BookItem: public TaxableItem{
protected:
    string author, isbn, bar;
public:
    string getIsbn() const;
    void setIsbn(string isbn);
    string getBar() const;
    void setBar(string bar);
    const string getAuthor() const;
    void setAuthor(string author);
    string getType() const;

public:

};

#endif //POS_BOOKITEM_H
