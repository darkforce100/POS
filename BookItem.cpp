//
// Created by Trenton Telge on 6/28/17.
//

#include "BookItem.h"

/**
 * Returns ISBN of book item instance
 *
 * @returns string ISBN of book item instance (this)
 * **/
string BookItem::getIsbn() const {
    return BookItem::isbn;
}

/**
 * Sets ISBN of book item instance
 *
 * @param string isbn ISBN of book item instance (this)
 * **/
void BookItem::setIsbn(string isbn) {
    BookItem::isbn = isbn;
}

/**
 * Returns bar code of book item instance
 *
 * @returns string bar code of book item instance (this)
 * **/
string BookItem::getBar() const {
    return BookItem::bar;
}

/**
 * Sets bar code of book item instance
 *
 * @param string bar bar code of book item instance (this)
 * **/
void BookItem::setBar(string bar) {
    BookItem::bar = bar;
}

/**
 * Returns Author of book item instance
 *
 * @returns string Author of book item instance (this)
 * **/
const string BookItem::getAuthor() const {
    return BookItem::author;
}

/**
 * Sets Author of book item instance
 *
 * @param string author Author of book item instance (this)
 * **/
void BookItem::setAuthor(const string author) {
    BookItem::author = author;
}

/**
 * Returns Type of item instance
 *
 * @override
 * @returns string Type of item instance (this)
 * **/
string BookItem::getType() const {
    return "BOOK";
}