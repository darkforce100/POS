/*
 * Trenton, Tommy, Tyler, Alvin
 * COSC 1337.5001
 * 7/6/2017
 * Point of Sale Program
 * Final Project
 * */

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Item.h"
#include "BookItem.h"
#include "GroceryItem.h"

using namespace std;

void generateLogInPanel();

void generateLoggedAdminPanel();

void writeCatalog();

void readCatalog();

void decodeToItem(string);

string encodeToString(Item);

string encodeToString(TaxableItem);

string encodeToString(GroceryItem);

string encodeToString(BookItem);

// Vectors to contain entire catalog
vector<Item> itemCatalog_untaxable;
vector<TaxableItem> itemCatalog_taxable;
vector<GroceryItem> itemCatalog_grocery;
vector<BookItem> itemCatalog_book;

// Vectors to contain items in cart
vector<Item> itemCart_untaxable;
vector<TaxableItem> itemCart_taxable;
vector<GroceryItem> itemCart_grocery;
vector<BookItem> itemCart_book;


/**
 * Displays the main menu and generates the clerk logic flow
 *
 * @returns int exit status code
 * **/
int main() {
    readCatalog();
    int choice = 0;
    bool continued = false;
    while (choice < 1 || choice > 3) {
        if (!continued) {
            cout << setw(60) << setfill('*') << "" << "\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n"
                 << setw(59) << "*    1) New Transaction" << "*\n"
                 << setw(59) << "*    2) Log In As Administrator" << "*\n"
                 << setw(59) << "*    3) Quit" << "*\n"
                 << setw(59) << "*" << "*\n"
                 << setw(60) << setfill('*') << "" << "\n";
            cin >> choice;
        } else {
            continued = false;
            choice = 1;
        }
        if (choice < 1 || choice > 3) { cout << "You have entered an invalid option. Please try again.\n"; }
        else {
            switch (choice) {
                case 1: {

                    int type = 0;
                    while (type < 1 || type > 4) {
                        cout << setw(60) << setfill('*') << "" << "\n"
                             << setfill(' ') << setw(59) << left << "*" << "*\n"
                             << setw(59) << "*    What category is the selected item in?" << "*\n"
                             << setw(59) << "*" << "*\n"
                             << setw(59) << "*    1) Books" << "*\n"
                             << setw(59) << "*    2) Grocery" << "*\n"
                             << setw(59) << "*    3) Other (Untaxable)" << "*\n"
                             << setw(59) << "*    4) Other (Taxable)" << "*\n"
                             << setw(59) << "*" << "*\n"
                             << setw(60) << setfill('*') << "" << "\n";
                        cin >> type;
                        if (type < 1 || type > 4) { cout << "You have entered an invalid option. Please try again.\n"; }
                    }
                    cout << setw(60) << setfill('*') << "" << "\n"
                         << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setfill(' ') << setw(59) << left << "*    Which item do you wish to add to the cart? "
                         << "*\n"
                         << setfill(' ') << setw(59) << left << "*" << "*\n";
                    int select, c = 1;
                    switch (type) {
                        case 1: {
                            for (BookItem i : itemCatalog_book) {
                                cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName()
                                     << "*\n";
                                c++;
                            }
                            cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                                 << setw(60) << setfill('*') << "" << "\n";
                            cin >> select;
                            itemCart_book.push_back((BookItem &&) itemCatalog_book.at((unsigned long) (select - 1)));
                            cout << "Added to cart.\n";
                            break;
                        }
                        case 2: {
                            for (GroceryItem i : itemCatalog_grocery) {
                                cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName()
                                     << "*\n";
                                c++;
                            }
                            cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                                 << setw(60) << setfill('*') << "" << "\n";
                            cin >> select;
                            itemCart_grocery.push_back(
                                    (GroceryItem &&) itemCatalog_grocery.at((unsigned long) (select - 1)));
                            cout << "Added to cart.\n";
                            break;
                        }
                        case 3: {
                            for (Item i : itemCatalog_untaxable) {
                                cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName()
                                     << "*\n";
                                c++;
                            }
                            cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                                 << setw(60) << setfill('*') << "" << "\n";
                            cin >> select;
                            itemCart_untaxable.push_back(
                                    (Item &&) itemCatalog_untaxable.at((unsigned long) (select - 1)));
                            cout << "Added to cart.\n";
                            break;
                        }
                        case 4: {
                            for (TaxableItem i : itemCatalog_taxable) {
                                cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName()
                                     << "*\n";
                                c++;
                            }
                            cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                                 << setw(60) << setfill('*') << "" << "\n";
                            cin >> select;
                            itemCart_taxable.push_back(
                                    (TaxableItem &&) itemCatalog_taxable.at((unsigned long) (select - 1)));
                            cout << "Added to cart.\n";
                            break;
                        }
                        default: {
                            cerr << "Category not available.\n";
                            break;
                        }

                    }
                    int cont = 0;
                    while (cont < 1 || cont > 2) {
                        cout << setw(60) << setfill('*') << "" << "\n"
                             << setfill(' ') << setw(59) << left << "*" << "*\n"
                             << setw(59) << "*    Would you like to add another item?" << "*\n"
                             << setw(59) << "*" << "*\n"
                             << setw(59) << "*    1) Add Item" << "*\n"
                             << setw(59) << "*    2) Finalize and Print Reciept" << "*\n"
                             << setw(59) << "*" << "*\n"
                             << setw(60) << setfill('*') << "" << "\n";
                        cin.ignore(50, '\n');
                        cin >> cont;
                        if (cont < 1 || cont > 2) { cout << "You have entered an invalid option. Please try again.\n"; }
                    }
                    switch (cont) {
                        case 1: {
                            continued = true;
                            choice = 0;
                            break;
                        }
                        case 2: {
                            double total = 0;
                            cout << setw(5) << left << setfill(' ') << "" << "Title" << setw(5) << "" << "*" << setw(5)
                                 << "" << "Total" << setw(5) << "" << "*" << setw(6) << "" << "Tax" << setw(6) << ""
                                 << "\n";
                            cout << setw(15) << left << "" << "*" << setw(15) << "" << "*" << setw(15) << "" << "\n";
                            for (Item i : itemCart_untaxable) {
                                cout << setw(15) << left << i.getName() << "*" << setw(5) << "Sub $" << setw(10)
                                     << setprecision(2) << fixed << right << i.getBasePrice() << "*" << setw(5) << left
                                     << "Rate" << setw(9) << right << "0.00" << "%\n";
                                cout << setw(15) << left << "" << "*" << setw(5) << "  + $" << right << setprecision(2)
                                     << fixed << setw(10) << 0 << "*" << left << setw(5) << "  = $" << setw(10) << right
                                     << i.getBasePrice() << "\n";
                                total += i.getBasePrice();
                            }
                            for (TaxableItem i : itemCart_taxable) {
                                cout << setw(15) << left << i.getName() << "*" << setw(5) << "Sub $" << setw(10)
                                     << setprecision(2) << fixed << right << i.getBasePrice() << "*" << setw(5) << left
                                     << "Rate" << setw(9) << right << i.getTaxRate() << "%\n";
                                cout << setw(15) << left << "" << "*" << setw(5) << "  + $" << right << setprecision(2)
                                     << fixed << setw(10) << i.getTaxAmount() << "*" << left << setw(5) << "  = $"
                                     << setw(10) << right << i.getTaxedPrice() << "\n";
                                total += i.getTaxedPrice();
                            }
                            for (GroceryItem i : itemCart_grocery) {
                                cout << setw(15) << left << i.getName() << "*" << setw(5) << "Sub $" << setw(10)
                                     << setprecision(2) << fixed << right << i.getBasePrice() << "*" << setw(5) << left
                                     << "Rate" << setw(9) << right << "0.00" << "%\n";
                                cout << setw(15) << left << "" << "*" << setw(5) << "  + $" << right << setprecision(2)
                                     << fixed << setw(10) << 0 << "*" << left << setw(5) << "  = $" << setw(10) << right
                                     << i.getBasePrice() << "\n";
                                total += i.getBasePrice();
                            }
                            for (BookItem i : itemCart_book) {
                                cout << setw(15) << left << i.getName() << "*" << setw(5) << "Sub $" << setw(10)
                                     << setprecision(2) << fixed << right << i.getBasePrice() << "*" << setw(5) << left
                                     << "Rate" << setw(9) << right << i.getTaxRate() << "%\n";
                                cout << setw(15) << left << "" << "*" << setw(5) << "  + $" << right << setprecision(2)
                                     << fixed << setw(10) << i.getTaxAmount() << "*" << left << setw(5) << "  = $"
                                     << setw(10) << right << i.getTaxedPrice() << "\n";
                                total += i.getTaxedPrice();
                            }
                            cout << setw(15) << left << "" << "*" << setw(15) << "" << "*" << setw(15) << "" << "\n";
                            cout << setw(15) << left << "" << "*" << setw(15) << "" << "*" << setw(15) << "" << "\n";
                            cout << setw(15) << left << "TOTAL" << "*" << setw(5) << "    $" << right << setw(10)
                                 << setprecision(2) << fixed << total << "*" << setw(15) << "" << "\n";
                            itemCart_untaxable = {};
                            itemCart_taxable = {};
                            itemCart_grocery = {};
                            itemCart_book = {};
                            main();
                            break;
                        }
                        default: {
                            cerr << "This action is not available.\n";
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    generateLogInPanel();
                    break;
                }
                case 3: {
                    cout << "Program exiting. Goodbye.\n";
                    return 0;
                }
                default: {
                    break;
                }
            }
        }
    }


    return 0;
}

/**
 * Generates a log in logic flow as access control to the admin area
 * **/
void generateLogInPanel() {
    const string correctPass = "11111";
    string password;
    cout << "Enter the admin password:\n";
    cin >> password;
    if (password != "11111") {
        cout << "You have entered the wrong password. Returning to main menu.\n";
        main();
    } else {
        generateLoggedAdminPanel();
    }

}

/**
 * Administrator area functionality
 * **/
void generateLoggedAdminPanel() {
    int choice = 0;
    cout << "Welcome, admin.\n\n";
    while (choice < 1 || choice > 4) {
        cout << setw(60) << setfill('*') << "" << "\n"
             << setfill(' ') << setw(59) << left << "*" << "*\n"
             << setw(59) << "*    1) Add an Item to Catalog" << "*\n"
             << setw(59) << "*    2) Edit an Item in Catalog" << "*\n"
             << setw(59) << "*    3) Delete an Item from Catalog" << "*\n"
             << setw(59) << "*    4) Log Out" << "*\n"
             << setw(59) << "*" << "*\n"
             << setw(60) << setfill('*') << "" << "\n";
        cin >> choice;
        if (choice < 1 || choice > 4) { cout << "You have entered an invalid option. Please try again.\n"; }
    }
    switch (choice) {
        case 1: {
            int type = 0;
            while (type < 1 || type > 3) {
                cout << setw(60) << setfill('*') << "" << "\n"
                     << setfill(' ') << setw(59) << left << "*" << "*\n"
                     << setw(59) << "*    What category does the item best fit in?" << "*\n"
                     << setw(59) << "*" << "*\n"
                     << setw(59) << "*    1) Books" << "*\n"
                     << setw(59) << "*    2) Grocery" << "*\n"
                     << setw(59) << "*    3) Other" << "*\n"
                     << setw(59) << "*" << "*\n"
                     << setw(60) << setfill('*') << "" << "\n";
                cin >> type;
                if (type < 1 || type > 3) { cout << "You have entered an invalid option. Please try again.\n"; }
            }
            switch (type) {
                case 1: {
                    string title, author;
                    string isbn, bar;
                    char taxOpt = ' ';
                    double tax, base;
                    cout << "What is the title of the book?\n";
                    cin.ignore();
                    getline(cin, title);
                    cin.ignore(256, '\n');
                    cout << "Who is the author of the book?\n";
                    getline(cin, author);
                    cin.ignore(256, '\n');
                    cout << "What is the ISBN number of this title(do not include dashes)? (Enter 0 if unsure)\n";
                    while ((isbn.length() < 10 || isbn.length() > 13) && isbn != "0") {
                        cin >> isbn;
                        if ((isbn.length() < 10 || isbn.length() > 13) && isbn != "0") {
                            cout << "Invalid isbn number. Enter again." << endl;
                            isbn = " ";
                        } else {
                            for (int i = 0; i < isbn.length(); i++) {
                                if (isdigit((isbn[i])) == 0) {
                                    cout << "Invalid isbn number. Enter again." << endl;
                                    isbn = " ";
                                }
                            }
                        }
                    }
                    cout << "What is the bar code for this title? (Enter 0 if unsure)\n";
                    while (bar.length() != 13 && bar != "0") {
                        cin >> bar;
                        if (bar.length() != 13 && bar != "0") {
                            cout << "Invalid barcode" << endl;
                            bar = " ";
                        } else {
                            for (int i = 0; i < bar.length(); i++) {
                                if (isdigit(bar[i]) == 0) {
                                    cout << "Invalid barcode" << endl;
                                    bar = " ";
                                }
                            }
                        }
                    }
                    cout << "Use the default tax rate? (8.25%) [Y\\N]\n";
                    while (tolower((int) taxOpt) != 'y' && tolower((int) taxOpt) != 'n') {
                        cin >> taxOpt;
                        if (tolower((int) taxOpt) != 'y' && tolower((int) taxOpt) != 'n') {
                            cout << "Invalid response. Please enter a Y or N.\n";
                        }
                    }
                    if (tolower((int) taxOpt) == 'y') {
                        tax = 8.25;
                        cout << "Default tax rate saved.\n";
                    } else {
                        cout << "What is the special tax rate for this item (in percent)?\n";
                        cin >> tax;
                    }
                    cout << "What is the base price for this title?\n";
                    cin >> base;
                    BookItem b;
                    b.setAuthor(author);
                    b.setName(title);
                    b.setIsbn(isbn);
                    b.setBar(bar);
                    b.setTaxRate(tax);
                    b.setBasePrice(base);
                    itemCatalog_book.push_back(b);
                    break;
                }
                case 2: {
                    string title;
                    double base;
                    td_s expiration;
                    int month = 0, day = 0, year = 0;
                    cout << "What is the name of the item?\n";
                    cin.ignore();
                    getline(cin, title);
                    cin.ignore(256, '\n');
                    cout << "What is the base price of this item?\n";
                    cin >> base;
                    cout << "What is the expiration date?  (Enter month, day, then year in digits)\n";
                    while (month <= 0 || month > 12) {
                        cin >> month;
                        if (month <= 0 || month > 12) {
                            cout << "Invalid month, enter again";
                        }
                    }
                    while (day <= 0 || day > 31) {
                        cin >> day;
                        if (day <= 0 || day > 31) {
                            cout << "Invalid day, enter again";
                        }
                    }
                    while (year < 1000 || year > 9999) {
                        cin >> year;
                        if (year < 1000 || year > 9999) {
                            cout << "Invalid year, enter again";
                        }
                    }
                    expiration.month = month;
                    expiration.day = day;
                    expiration.year = year;
                    GroceryItem g;
                    g.setName(title);
                    g.setBasePrice(base);
                    g.setExpiration(expiration);
                    itemCatalog_grocery.push_back(g);
                    break;
                }
                case 3: {
                    string title;
                    double base, tax;
                    char isTaxable = ' ', taxOpt = ' ';
                    cout << "What is the name of the item?";
                    cin.ignore();
                    getline(cin, title);
                    cin.ignore(256, '\n');
                    cout << "What is the base price of this item?";
                    cin >> base;
                    cout << "Is this item taxable? [Y\\N]\n";
                    while (tolower((int) isTaxable) != 'y' && tolower((int) isTaxable) != 'n') {
                        cin >> isTaxable;
                        if (tolower((int) isTaxable) != 'y' && tolower((int) isTaxable) != 'n') {
                            cout << "Invalid response. Please enter a Y or N.\n";
                        }
                    }
                    if (tolower((int) isTaxable) == 'y') {
                        cout << "Use the default tax rate? (8.25%) [Y\\N]\n";
                        while (tolower((int) taxOpt) != 'y' && tolower((int) taxOpt) != 'n') {
                            cin >> taxOpt;
                            if (tolower((int) taxOpt) != 'y' && tolower((int) taxOpt) != 'n') {
                                cout << "Invalid response. Please enter a Y or N.\n";
                            }
                        }
                        if (tolower((int) taxOpt) == 'y') {
                            tax = 8.25;
                            cout << "Default tax rate saved.\n";
                        } else {
                            cout << "What is the special tax rate for this item (in percent)?\n";
                            cin >> tax;
                        }
                        TaxableItem i;
                        i.setName(title);
                        i.setBasePrice(base);
                        i.setTaxRate(tax);
                        itemCatalog_taxable.push_back(i);
                    } else {
                        Item i;
                        i.setName(title);
                        i.setBasePrice(base);
                        itemCatalog_untaxable.push_back(i);
                    }
                    break;
                }
                default:
                    break;
            }
            writeCatalog();
            generateLoggedAdminPanel();
            break;
        }
        case 2: {
            int type = 0;
            while (type < 1 || type > 4) {
                cout << setw(60) << setfill('*') << "" << "\n"
                     << setfill(' ') << setw(59) << left << "*" << "*\n"
                     << setw(59) << "*    What category is the item in?" << "*\n"
                     << setw(59) << "*" << "*\n"
                     << setw(59) << "*    1) Books" << "*\n"
                     << setw(59) << "*    2) Grocery" << "*\n"
                     << setw(59) << "*    3) Other Untaxed" << "*\n"
                     << setw(59) << "*    4) Other Taxed" << "*\n"
                     << setw(59) << "*" << "*\n"
                     << setw(60) << setfill('*') << "" << "\n";
                cin >> type;
                if (type < 1 || type > 4) { cout << "You have entered an invalid option. Please try again.\n"; }
            }
            cout << setw(60) << setfill('*') << "" << "\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n"
                 << setfill(' ') << setw(59) << left << "*    Which item do you wish to edit? " << "*\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n";
            int c = 1, select, fieldSelect;
            switch (type) {
                case 1: {
                    for (const BookItem i : itemCatalog_book) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(60) << setfill('*') << "" << "\n";
                    cin >> select;
                    cout << setw(60) << setfill('*') << "" << "\n"
                         << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(59) << "*    Which field do you wish to edit? " << "*\n"
                         << setw(59) << "*" << "*\n"
                         << setw(59) << "*    1) Title" << "*\n"
                         << setw(59) << "*    2) Author" << "*\n"
                         << setw(59) << "*    3) Base Price" << "*\n"
                         << setw(59) << "*    4) Tax Rate" << "*\n"
                         << setw(59) << "*    5) ISBN" << "*\n"
                         << setw(59) << "*    6) Bar Code" << "*\n"
                         << setw(59) << "*" << "*\n"
                         << setfill('*') << setw(60) << "" << "\n";
                    cin >> fieldSelect;
                    switch (fieldSelect) {
                        case 1: {
                            string title;
                            cout << "The current title is "
                                 << itemCatalog_book.at((unsigned long) (select - 1)).getName() << "\n";
                            cout << "What should the amended title be?\n";
                            cin.ignore();
                            getline(cin, title);
                            itemCatalog_book.at((unsigned long) (select - 1)).setName(title);
                            break;
                        }
                        case 2: {
                            string author;
                            cout << "The current author is "
                                 << itemCatalog_book.at((unsigned long) (select - 1)).getAuthor() << "\n";
                            cout << "What should the amended author be?\n";
                            cin.ignore();
                            getline(cin, author);
                            itemCatalog_book.at((unsigned long) (select - 1)).setAuthor(author);
                            break;
                        }
                        case 3: {
                            double base;
                            cout << "The current price is " << setprecision(2) << fixed
                                 << itemCatalog_book.at((unsigned long) (select - 1)).getBasePrice() << "\n";
                            cout << "What should the amended price be?\n";
                            cin >> base;
                            itemCatalog_book.at((unsigned long) (select - 1)).setBasePrice(base);
                            break;
                        }
                        case 4: {
                            double tax;
                            cout << "The current tax rate is " << setprecision(2) << fixed
                                 << itemCatalog_book.at((unsigned long) (select - 1)).getTaxRate() * 100 << "%\n";
                            cout << "What should the new tax rate (as a percentage) be?\n";
                            cin >> tax;
                            itemCatalog_book.at((unsigned long) (select - 1)).setTaxRate(tax);
                            break;
                        }
                        case 5: {
                            string isbn;
                            cout << "The current ISBN is "
                                 << itemCatalog_book.at((unsigned long) (select - 1)).getIsbn() << "\n";
                            cout
                                    << "What is the amended ISBN number of this title(do not include dashes)? (Enter 0 if unsure)\n";
                            while ((isbn.length() < 10 || isbn.length() > 13) && isbn != "0") {
                                cin >> isbn;
                                if ((isbn.length() < 10 || isbn.length() > 13) && isbn != "0") {
                                    cout << "Invalid isbn number. Enter again." << endl;
                                    isbn = " ";
                                } else {
                                    for (int i = 0; i < isbn.length(); i++) {
                                        if (isdigit((isbn[i])) == 0) {
                                            cout << "Invalid isbn number. Enter again." << endl;
                                            isbn = " ";
                                        }
                                    }
                                }
                            }
                            itemCatalog_book.at((unsigned long) (select - 1)).setIsbn(isbn);
                            break;
                        }
                        case 6: {
                            string bar;
                            cout << "The current bar is " << itemCatalog_book.at((unsigned long) (select - 1)).getBar()
                                 << "\n";
                            cout << "What is the bar code for this title? (Enter 0 if unsure)\n";
                            while (bar.length() != 13 && bar != "0") {
                                cin >> bar;
                                if (bar.length() != 13 && bar != "0") {
                                    cout << "Invalid barcode" << endl;
                                    bar = " ";
                                } else {
                                    for (int i = 0; i < bar.length(); i++) {
                                        if (isdigit(bar[i]) == 0) {
                                            cout << "Invalid barcode" << endl;
                                            bar = " ";
                                        }
                                    }
                                }
                            }
                            itemCatalog_book.at((unsigned long) (select - 1)).setBar(bar);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    for (const GroceryItem i : itemCatalog_grocery) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(60) << setfill('*') << "" << "\n";
                    cin >> select;
                    cout << setw(60) << setfill('*') << "" << "\n"
                         << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(59) << "*    Which field do you wish to edit? " << "*\n"
                         << setw(59) << "*" << "*\n"
                         << setw(59) << "*    1) Title" << "*\n"
                         << setw(59) << "*    2) Base Price" << "*\n"
                         << setw(59) << "*    3) Expiration Date" << "*\n"
                         << setw(59) << "*" << "*\n"
                         << setfill('*') << setw(60) << "" << "\n";
                    cin >> fieldSelect;
                    switch (fieldSelect) {
                        case 1: {
                            string title;
                            cout << "The current title is "
                                 << itemCatalog_grocery.at((unsigned long) (select - 1)).getName() << "\n";
                            cout << "What should the amended title be?\n";
                            cin.ignore();
                            getline(cin, title);
                            itemCatalog_grocery.at((unsigned long) (select - 1)).setName(title);
                            break;
                        }
                        case 2: {
                            double base;
                            cout << "The current price is " << setprecision(2) << fixed
                                 << itemCatalog_grocery.at((unsigned long) (select - 1)).getBasePrice() << "\n";
                            cout << "What should the amended price be?\n";
                            cin >> base;
                            itemCatalog_grocery.at((unsigned long) (select - 1)).setBasePrice(base);
                            break;
                        }
                        case 3: {
                            td_s expiration;
                            int month = 0, day = 0, year = 0;
                            cout << "The current expiration date is "
                                 << itemCatalog_grocery.at((unsigned long) (select - 1)).getExpiration().day << "/"
                                 << itemCatalog_grocery.at((unsigned long) (select - 1)).getExpiration().month << "/"
                                 << itemCatalog_grocery.at((unsigned long) (select - 1)).getExpiration().year
                                 << "\n";
                            cout << "What is the amended expiration date?  (Enter month, day, then year in digits)\n";
                            while (month <= 0 || month > 12) {
                                cin >> month;
                                if (month <= 0 || month > 12) {
                                    cout << "Invalid month, enter again";
                                }
                            }
                            while (day <= 0 || day > 31) {
                                cin >> day;
                                if (day <= 0 || day > 31) {
                                    cout << "Invalid day, enter again";
                                }
                            }
                            while (year < 1000 || year > 9999) {
                                cin >> year;
                                if (year < 1000 || year > 9999) {
                                    cout << "Invalid year, enter again";
                                }
                            }
                            expiration.month = month;
                            expiration.day = day;
                            expiration.year = year;
                            itemCatalog_grocery.at((unsigned long) (select - 1)).setExpiration(expiration);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case 3: {
                    for (const Item i : itemCatalog_untaxable) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(60) << setfill('*') << "" << "\n";
                    cin >> select;
                    cout << setw(60) << setfill('*') << "" << "\n"
                         << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(59) << "*    Which field do you wish to edit? " << "*\n"
                         << setw(59) << "*" << "*\n"
                         << setw(59) << "*    1) Title" << "*\n"
                         << setw(59) << "*    2) Base Price" << "*\n"
                         << setw(59) << "*" << "*\n"
                         << setfill('*') << setw(60) << "" << "\n";
                    cin >> fieldSelect;
                    switch (fieldSelect) {
                        case 1: {
                            string title;
                            cout << "The current title is "
                                 << itemCatalog_untaxable.at((unsigned long) (select - 1)).getName() << "\n";
                            cout << "What should the amended title be?\n";
                            cin.ignore();
                            getline(cin, title);
                            itemCatalog_untaxable.at((unsigned long) (select - 1)).setName(title);
                            break;
                        }
                        case 2: {
                            double base;
                            cout << "The current price is " << setprecision(2) << fixed
                                 << itemCatalog_untaxable.at((unsigned long) (select - 1)).getBasePrice() << "\n";
                            cout << "What should the amended price be?\n";
                            cin >> base;
                            itemCatalog_untaxable.at((unsigned long) (select - 1)).setBasePrice(base);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                case 4: {
                    for (const TaxableItem i : itemCatalog_taxable) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(60) << setfill('*') << "" << "\n";
                    cin >> select;
                    cout << setw(60) << setfill('*') << "" << "\n"
                         << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(59) << "*    Which field do you wish to edit? " << "*\n"
                         << setw(59) << "*" << "*\n"
                         << setw(59) << "*    1) Title" << "*\n"
                         << setw(59) << "*    2) Base Price" << "*\n"
                         << setw(59) << "*    3) Tax Rate" << "*\n"
                         << setw(59) << "*" << "*\n"
                         << setfill('*') << setw(60) << "" << "\n";
                    cin >> fieldSelect;
                    switch (fieldSelect) {
                        case 1: {
                            string title;
                            cout << "The current title is "
                                 << itemCatalog_taxable.at((unsigned long) (select - 1)).getName() << "\n";
                            cout << "What should the amended title be?\n";
                            cin.ignore();
                            getline(cin, title);
                            itemCatalog_taxable.at((unsigned long) (select - 1)).setName(title);
                            break;
                        }
                        case 2: {
                            double base;
                            cout << "The current price is " << setprecision(2) << fixed
                                 << itemCatalog_taxable.at((unsigned long) (select - 1)).getBasePrice() << "\n";
                            cout << "What should the amended price be?\n";
                            cin >> base;
                            itemCatalog_taxable.at((unsigned long) (select - 1)).setBasePrice(base);
                            break;
                        }
                        case 3: {
                            double tax;
                            cout << "The current tax rate is " << setprecision(2) << fixed
                                 << itemCatalog_taxable.at((unsigned long) (select - 1)).getTaxRate() << "%\n";
                            cout << "What should the new tax rate (as a percentage) be?\n";
                            cin >> tax;
                            itemCatalog_taxable.at((unsigned long) (select - 1)).setTaxRate(tax);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
                default: {
                    cerr << "An invalid input was recieved.";
                    break;
                }
            }
            cout << "Item successfully edited.\n";
            writeCatalog();
            generateLoggedAdminPanel();
            break;
        }
        case 3: {
            int type = 0;
            while (type < 1 || type > 4) {
                cout << setw(60) << setfill('*') << "" << "\n"
                     << setfill(' ') << setw(59) << left << "*" << "*\n"
                     << setw(59) << "*    What category is the item in?" << "*\n"
                     << setw(59) << "*" << "*\n"
                     << setw(59) << "*    1) Books" << "*\n"
                     << setw(59) << "*    2) Grocery" << "*\n"
                     << setw(59) << "*    3) Other Untaxed" << "*\n"
                     << setw(59) << "*    4) Other Taxed" << "*\n"
                     << setw(59) << "*" << "*\n"
                     << setw(60) << setfill('*') << "" << "\n";
                cin >> type;
                if (type < 1 || type > 4) { cout << "You have entered an invalid option. Please try again.\n"; }
            }
            cout << setw(60) << setfill('*') << "" << "\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n"
                 << setfill(' ') << setw(59) << left << "*    Which item do you wish to delete? " << "*\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n";
            int c = 1, select;
            switch (type) {
                case 1: {
                    for (const BookItem i : itemCatalog_book) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(60) << setfill('*') << "" << "\n";
                    cin >> select;
                    itemCatalog_book.erase(itemCatalog_book.begin() + select - 1);
                    break;
                }
                case 2: {
                    for (const GroceryItem i : itemCatalog_grocery) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(60) << setfill('*') << "" << "\n";
                    cin >> select;
                    itemCatalog_grocery.erase(itemCatalog_grocery.begin() + select - 1);
                    break;
                }
                case 3: {
                    for (const Item i : itemCatalog_untaxable) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(60) << setfill('*') << "" << "\n";
                    cin >> select;
                    itemCatalog_untaxable.erase(itemCatalog_untaxable.begin() + select - 1);
                    break;
                }
                case 4: {
                    for (const TaxableItem i : itemCatalog_taxable) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cout << setfill(' ') << setw(59) << left << "*" << "*\n"
                         << setw(60) << setfill('*') << "" << "\n";
                    cin >> select;
                    itemCatalog_taxable.erase(itemCatalog_taxable.begin() + select - 1);
                    break;
                }
                default: {
                    cerr << "An invalid input was recieved.";
                    break;
                }
            }
            cout << "Item removed from catalog.\n";
            writeCatalog();
            generateLoggedAdminPanel();
            break;
        }
        case 4: {
            main();
            break;
        }
        default:
            cerr << "An invalid input was recieved.";
            break;
    }
}

/**
 * Reads the catalog file to the vectors
 * **/
void readCatalog() {
    ifstream catFile;
    catFile.open("items.cat");
    string s;
    itemCatalog_untaxable = {};
    itemCatalog_taxable = {};
    itemCatalog_grocery = {};
    itemCatalog_book = {};
    while (getline(catFile, s)) {
        decodeToItem(s);
    }
    catFile.close();
}

/**
 * Writes the vectors to the catalog file
 * **/
void writeCatalog() {
    ofstream catFile;
    catFile.open("items.cat");
    for (const Item i : itemCatalog_untaxable) {
        catFile << encodeToString(i) << "\n";
    }
    for (const TaxableItem i : itemCatalog_taxable) {
        catFile << encodeToString(i) << "\n";
    }
    for (const GroceryItem i : itemCatalog_grocery) {
        catFile << encodeToString(i) << "\n";
    }
    for (const BookItem i : itemCatalog_book) {
        catFile << encodeToString(i) << "\n";
    }
    catFile.close();
};

/**
 * Parses an encoded item string to an Item object or relevant child, and adds that item to the appropriate vector
 *
 * @param string s String to parse
 * **/
void decodeToItem(string s) {
    if (s.find("TAXABLE") == 0) {
        TaxableItem i;
        //Parse string as taxable item
        unsigned long firstSentinel = s.find_first_of("|");
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setName(s.substr(0, firstSentinel));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setBasePrice(stod(s.substr(0, firstSentinel)));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        i.setTaxRate(stod(s.substr(0, s.length())));
        itemCatalog_taxable.push_back(i);
    } else if (s.find("UNTAXABLE") == 0) {
        Item i;
        //Parse string as generic untaxable item
        unsigned long firstSentinel = s.find_first_of("|");
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setName(s.substr(0, firstSentinel));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        i.setBasePrice(stod(s.substr(0, s.length())));
        itemCatalog_untaxable.push_back(i);
    } else if (s.find("BOOK") == 0) {
        BookItem i;
        //Parse string as book item
        unsigned long firstSentinel = s.find_first_of("|");
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setName(s.substr(0, firstSentinel));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setBasePrice(stod(s.substr(0, firstSentinel)));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setTaxRate(stod(s.substr(0, firstSentinel)));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setAuthor(s.substr(0, firstSentinel));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setBar(s.substr(0, firstSentinel));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        i.setIsbn(s.substr(0, s.length()));
        itemCatalog_book.push_back(i);
    } else if (s.find("GROCERY") == 0) {
        GroceryItem i;
        string ed;
        int day, month, year;
        //Parse string as grocery item
        unsigned long firstSentinel = s.find_first_of("|");
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setName(s.substr(0, firstSentinel));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setBasePrice(stod(s.substr(0, firstSentinel)));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        ed = s.substr(0, s.length());
        //Parse expiration date
        firstSentinel = ed.find_first_of(".");
        day = stoi(ed.substr(0, firstSentinel));
        ed = ed.substr(firstSentinel + 1, ed.length() - 1);
        firstSentinel = ed.find_first_of(".");
        month = stoi(ed.substr(0, firstSentinel));
        ed = ed.substr(firstSentinel + 1, ed.length() - 1);
        year = stoi(ed.substr(0, ed.length()));
        td_s exp;
        exp.day = day;
        exp.month = month;
        exp.year = year;
        i.setExpiration(exp);
        itemCatalog_grocery.push_back(i);
    } else {
        cerr << "Item type cannot be parsed from file.\n";
    }
}

/**
 * Generates a string object containing all informatic fields of the Item argument
 *
 * @param Item i Item to return as string
 * @returns string Encoded string
 * **/
string encodeToString(Item i) {
    string s;
    s = "UNTAXABLE|" + i.getName() + "|" + to_string(i.getBasePrice());
    // {Type} {Name} {Base Price}
    return s;
}

/**
 * Generates a string object containing all informatic fields of the TaxableItem argument
 *
 * @param TaxableItem i Item to return as string
 * @returns string Encoded string
 * **/
string encodeToString(TaxableItem i) {
    string s;
    s = "TAXABLE|" + i.getName() + "|" + to_string(i.getBasePrice()) + "|" + to_string(i.getTaxRate());
    return s;
}

/**
 * Generates a string object containing all informatic fields of the GroceryItem argument
 *
 * @param GroceryItem i Item to return as string
 * @returns string Encoded string
 * **/
string encodeToString(GroceryItem i) {
    string s;
    int day, month, year;
    string exp;
    day = i.getExpiration().day;
    if (day < 10) {
        exp = "0" + to_string(day) + ".";
    } else {
        exp = to_string(day) + ".";
    }
    month = i.getExpiration().month;
    if (month < 10) {
        exp = exp + "0" + to_string(month) + ".";
    } else {
        exp = exp + to_string(month) + ".";
    }
    year = i.getExpiration().year;
    exp = exp + to_string(year);
    s = "GROCERY|" + i.getName() + "|" + to_string(i.getBasePrice()) + "|" + exp;
    return s;
}

/**
 * Generates a string object containing all informatic fields of the BookItem argument
 *
 * @param BookItem i Item to return as string
 * @returns string Encoded string
 * **/
string encodeToString(BookItem i) {
    string s;
    s = "BOOK|" + i.getName() + "|" + to_string(i.getBasePrice()) + "|" + to_string(i.getTaxRate()) + "|" +
        i.getAuthor() + "|" + i.getBar() + "|" + i.getIsbn();
    return s;
}