//
// Created by Trenton Telge on 6/28/17.
//

#include "BookItem.h"

string BookItem::getIsbn() const {
    return BookItem::isbn;
}

void BookItem::setIsbn(string isbn) {
    BookItem::isbn = isbn;
}

string BookItem::getBar() const {
    return BookItem::bar;
}

void BookItem::setBar(string bar) {
    BookItem::bar = bar;
}

const string BookItem::getAuthor() const {
    return BookItem::author;
}

void BookItem::setAuthor(const string author) {
    BookItem::author = author;
}

string BookItem::getType() const {
    return "BOOK";
}