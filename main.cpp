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
int main();

vector <Item> itemCatalog_untaxable;
vector <TaxableItem> itemCatalog_taxable;
vector <GroceryItem> itemCatalog_grocery;
vector <BookItem> itemCatalog_book;

int main() {

    /**
     * DEBUG ONLY DELETE FOR PROD
     * **/
    Item i;
    i.setName("Llamas");
    i.setBasePrice(20.00);
    itemCatalog_untaxable.push_back(i);
    GroceryItem g;
    g.setName("Fruitcake");
    g.setBasePrice(123.45);
    itemCatalog_grocery.push_back(g);
    /**
    * DEBUG ONLY DELETE FOR PROD
    * **/

  int choice = 0;
  while(choice < 1 || choice > 3){
    cout << setw(60) << setfill('*') << "" << "\n"
         << setfill(' ') << setw(59) << left << "*" << "*\n"
         << setw(59) << "*    1) New Transaction" << "*\n"
         << setw(59) << "*    2) Log In As Administrator" << "*\n"
         << setw(59) << "*    3) Generate Report" << "*\n"
         << setw(59) << "*" << "*\n"
         << setw(60) << setfill('*') << "" << "\n";
      cin >> choice;
    if (choice < 1 || choice > 3){cout << "You have entered an invalid option. Please try again.\n";}
  }
  switch(choice){
    case 1: {
        //TODO Enable item search to add to cart
        cout << "You can search items by title.\n"
             << "Entering \"list\", \"catalog\", or \"all\" will list all items in the catalog by title.\n"
             << "Enter a term to search by below:\n";
        string searchTerm;
        cin >> searchTerm;
        for (Item i : itemCatalog_untaxable) {
            if (i.getName().find(searchTerm) != string::npos) {
                //TODO add i to menu
            }
        }
        for (TaxableItem i : itemCatalog_taxable) {
            if (i.getName().find(searchTerm) != string::npos) {
                //TODO add i to menu
            }
        }
        for (BookItem i : itemCatalog_book) {
            if (i.getName().find(searchTerm) != string::npos) {
                //TODO add i to menu
            }
        }
        for (GroceryItem i : itemCatalog_grocery) {
            if (i.getName().find(searchTerm) != string::npos) {
                //TODO add i to menu
            }
        }
        break;
    }
    case 2: {
        generateLogInPanel();
        break;
    }
    case 3: {
        //TODO generate a sales report
        break;
    }
    default: {
        break;
    }
  }

    return 0;
}

void generateLogInPanel(){
    const string correctPass = "11111";
    string password;
    cout << "Enter the admin password:\n";
    cin >> password;
    if(password != "11111")
    {
        cout << "You have entered the wrong password. Returning to main menu.\n";
        main();
    }
    else
    {
        generateLoggedAdminPanel();
    }

}
void generateLoggedAdminPanel(){
    int choice  = 0;
    cout << "Welcome, admin.\n\n";
    readCatalog();
    while(choice < 1 || choice > 4){
        cout << setw(60) << setfill('*') << "" << "\n"
             << setfill(' ') << setw(59) << left << "*" << "*\n"
             << setw(59) << "*    1) Add an Item to Catalog" << "*\n"
             << setw(59) << "*    2) Edit an Item in Catalog" << "*\n"
             << setw(59) << "*    3) Delete an Item from Catalog" << "*\n"
             << setw(59) << "*    4) Return to Main" << "*\n"
             << setw(59) << "*" << "*\n"
             << setw(60) << setfill('*') << "" << "\n";
        cin >> choice;
        if (choice < 1 || choice > 4){cout << "You have entered an invalid option. Please try again.\n";}
    }
    switch(choice){
        case 1: {
            int type = 0;
            while(type < 1 || type > 3){
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
                if (type < 1 || type > 3){cout << "You have entered an invalid option. Please try again.\n";}
            }
            switch(type) {
                case 1: {
                    string title, author;
                    string isbn, bar;
                    char taxOpt = ' ';
                    double tax, base;
                    cout << "What is the title of the book?\n";
                    getline(cin, title);
                    cin.ignore(256, '\n');
                    cout << "Who is the author of the book?\n";
                    getline(cin, author);
                    cin.ignore(256, '\n');
                    cout << "What is the ISBN number of this title(do not include dashes)? (Enter 0 if unsure)\n";
                    while((isbn.length() < 10 || isbn.length() > 13) && isbn != "0")
                    {
                        cin >> isbn;
                        if((isbn.length() < 10 || isbn.length() > 13) && isbn != "0")
                        {
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
                    while (bar.length() != 13 && bar != "0")
                    {
                        cin >> bar;
                        if(bar.length() != 13 && bar != "0")
                        {
                            cout << "Invalid barcode" << endl;
                            bar = " ";
                        }
                        else {
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
                    //TODO Requests item info, generates appropriate object, and adds to catalog vector.
                    string title;
                    double base;
                    td_s expiration;
                    int month, day, year;
                    break;
                }
                case 3: {
                    string title;
                    double base, tax;
                    char isTaxable = ' ', taxOpt = ' ';
                    cout << "What is the name of the item?";
                    cin >> title;
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
            break;
        }
        case 2: {
            int type = 0;
            while(type < 1 || type > 4){
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
                if (type < 1 || type > 4){cout << "You have entered an invalid option. Please try again.\n";}
            }
            cout << setw(60) << setfill('*') << "" << "\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n"
                 << setfill(' ') << setw(59) << left << "*    Which item do you wish to edit? " << "*\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n";
            int c = 1, select;
            switch(type) {
                case 1: {
                    for (const BookItem i : itemCatalog_book) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cin >> select;
                    //TODO edit a book
                    break;
                }
                case 2: {
                    for (const GroceryItem i : itemCatalog_grocery) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cin >> select;
                    //TODO edit a grocery
                    break;
                }
                case 3: {
                    for (const Item i : itemCatalog_untaxable) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cin >> select;
                    //TODO edit an untaxable
                    break;
                }
                case 4: {
                    for (const TaxableItem i : itemCatalog_taxable) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cin >> select;
                    //TODO edit a taxable
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
            while(type < 1 || type > 4){
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
                if (type < 1 || type > 4){cout << "You have entered an invalid option. Please try again.\n";}
            }
            cout << setw(60) << setfill('*') << "" << "\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n"
                 << setfill(' ') << setw(59) << left << "*    Which item do you wish to delete? " << "*\n"
                 << setfill(' ') << setw(59) << left << "*" << "*\n";
            int c = 1, select;
            switch(type) {
                case 1: {
                    for (const BookItem i : itemCatalog_book) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cin >> select;
                    itemCatalog_book.erase(itemCatalog_book.begin() + select - 1);
                    break;
                }
                case 2: {
                    for (const GroceryItem i : itemCatalog_grocery) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cin >> select;
                    itemCatalog_grocery.erase(itemCatalog_grocery.begin() + select - 1);
                    break;
                }
                case 3: {
                    for (const Item i : itemCatalog_untaxable) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
                    cin >> select;
                    itemCatalog_untaxable.erase(itemCatalog_untaxable.begin() + select - 1);
                    break;
                }
                case 4: {
                    for (const TaxableItem i : itemCatalog_taxable) {
                        cout << setfill(' ') << left << "*    " << c << ") " << setw(51) << i.getName() << "*\n";
                        c++;
                    }
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

void readCatalog(){
    ifstream catFile;
    catFile.open("items.cat");
    string s;
    itemCatalog_untaxable = {};
    itemCatalog_taxable = {};
    itemCatalog_grocery = {};
    itemCatalog_book = {};
    while (getline(catFile, s))
    {
        decodeToItem(s);
    }
    catFile.close();
}

void writeCatalog(){
    ofstream catFile;
    catFile.open("items.cat");
    for(const Item i : itemCatalog_untaxable){
        catFile << encodeToString(i) << "\n";
    }
    for(const TaxableItem i : itemCatalog_taxable){
        catFile << encodeToString(i) << "\n";
    }
    for(const GroceryItem i : itemCatalog_grocery){
        catFile << encodeToString(i) << "\n";
    }
    for(const BookItem i : itemCatalog_book){
        catFile << encodeToString(i) << "\n";
    }
    catFile.close();
};

void decodeToItem(string s){
    //TODO Generate appropriate Item for string and add to cat
    if (s.find("TAXABLE") == 0){
        TaxableItem i;
        //Parse string as taxable item
        unsigned long firstSentinel = s.find_first_of("|");
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setName(s.substr(0, firstSentinel - 1));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        firstSentinel = s.find_first_of("|");
        i.setBasePrice(stod(s.substr(0, firstSentinel - 1)));
        s = s.substr(firstSentinel + 1, s.length() - 1);
        i.setTaxRate(100 * stod(s.substr(0, s.length() -1)));
        itemCatalog_taxable.push_back(i);
    } else if (s.find("UNTAXABLE") == 0){
        Item i;
        //Parse string as generic untaxable item
    } else if (s.find("BOOK") == 0){
        BookItem i;
        //Parse string as book item
    } else if (s.find("GROCERY") == 0){
        GroceryItem i;
        //Parse string as grocery item
    } else {
        //This should never ever happen :(
        cerr << "FATAL ERROR - Mkpt 1" << s;
    }
}
string encodeToString(Item i){
    string s;
    s = "UNTAXABLE|" + i.getName() + "|" + to_string(i.getBasePrice());
    // {Type} {Name} {Base Price}
    return s;
}
string encodeToString(TaxableItem i){
    string s;
    s = "TAXABLE|" + i.getName() + "|" + to_string(i.getBasePrice()) + "|" + to_string(i.getTaxRate());
    return s;
}
string encodeToString(GroceryItem i){
    string s;
    int day, month, year;
    string exp;
    day = i.getExpiration().day;
    if (day < 10){
        exp = "0" + to_string(day) + ".";
    } else {
        exp = to_string(day) + ".";
    }
    month = i.getExpiration().month;
    if (month < 10){
        exp = exp + "0" + to_string(month) + ".";
    } else {
        exp = exp + to_string(month) + ".";
    }
    year = i.getExpiration().year;
    exp = exp + to_string(year);
    s = "GROCERY|" + i.getName() + "|" + to_string(i.getBasePrice()) + "|" + exp;
    return s;
}
string encodeToString(BookItem i){
    string s;
    s = "BOOK|" + i.getName() + "|" + to_string(i.getBasePrice()) + "|" + to_string(i.getTaxRate()) + "|" + i.getAuthor() + "|" + i.getBar() + "|" + i.getIsbn();
    return s;
}
