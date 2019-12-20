//Authors:Morgan Smithson
//Name:main
//Purpose: Menu for program5

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "iofun.h"
#include "portfolio.h"
#include "transaction.h"
#include "stock.h"

using namespace std;

//prototypes
int menu();
void buy_stock(Portfolio & portfolio);
void sell_stock(Portfolio & portfolio);
void holdings_stock(Portfolio & portfolio);
void gainslosses_stock(Portfolio & portfolio);
void remove_stock(Portfolio & portfolio);
void load(Portfolio & portfolio);
void save(Portfolio & portfolio);

int main()
{

	int choice;
	enum menu_choice {BUY=1, SELL, HOLDINGS, GAINSLOSSES, REMOVE, QUIT};
	Portfolio portfolio;

	//load the stock data base
	load(portfolio);

	//display the menu
	do {
		choice = menu();

		//do the menue choice
		if(choice ==  BUY) {
			buy_stock(portfolio);
		} else if(choice == SELL) {
			sell_stock(portfolio);
		} else if(choice == HOLDINGS) {
                        holdings_stock(portfolio);
		} else if(choice == GAINSLOSSES) {
                        gainslosses_stock(portfolio);
		} else if(choice == REMOVE) {
                        remove_stock(portfolio);
		}
	}while(choice != QUIT);

	//save the stock database
	save(portfolio);

}

//display a menu and return the user's selection
int menu()
{
	ostringstream os;

//construct the menu
    os << endl
       << "\tStock Portfolio Management System" << endl
       << "\t    Please Make a Selection" <<endl
       << "\t1 -- Buy a Stock" << endl
       << "\t2 -- Sell a Stock" << endl
       << "\t3 -- Report Current Holdings" << endl
       << "\t4 -- Report Gains and Losses" << endl
       << "\t5 -- Remove a Current Holding" << endl
       << "\t6 -- Done! (quit)" << endl
       << endl
       << "\tYour Choice? ";

	return  prompt_int_range(os.str(), 1, 6);
}

//save to a file
void save(Portfolio & portfolio)
{
    ofstream file;

    //open the file
    file.open("PORTFOLIO.DAT");
    if(not file) {
        cout << "Could not open file for writing" << endl;
        return;
    }

    //write the number of entries
    file << portfolio.get_size() << endl;
    for(int i=0; i<portfolio.get_size(); i++) {
        Stock stock = portfolio.get_stock(i);

        //write the stock symbol
        file << stock.get_symbol() << endl;

        //write the number of contact info parts
        file << stock.get_size() << endl;
        for(int j=0; j<stock.get_size(); j++) {
            Transaction info = stock.get_info(j);
            file << info.get_date() << endl
                 << info.get_company() << endl
                 << info.get_quantity() << endl
		 << info.get_price() << endl;
        }
    }

    file.close();
}


//load portfolio from a file
void load(Portfolio & portfolio)
{
    ifstream file;

    //open the file
    file.open("PORTFOLIO.DAT");
    if(not file) {
        return;
    }

    //read the number of entries
    int nc;
    file >> nc;
    file.get(); //consume newline

    for(int i=0; i<nc; i++) {
        Stock stock;

        //get symbol
        string symbol;
        getline(file, symbol);
        stock.set_symbol(symbol);

        //get the info entries
        int ni; //number of info entries
        file >> ni;
        file.get(); //consume newline

        for(int j=0; j<ni; j++) {
            string date, company;
            getline(file, date);
            getline(file, company);
	    int quantity;
	    file >> quantity;
	    double price;
	    file >> price;


            //add via anonymous object
            stock.add(Transaction{date, company, quantity, price});
        }

        //add the contact to the address book
        portfolio.add(stock);
    }

    file.close();
}



//buy a stock
void buy_stock(Portfolio & portfolio)
{
	string symbol;
	string date;
	string company;
	int quantity;
	double price;
	Stock stock;

	//get the date of the stock
	cout << "Date> ";
	if(cin.peek() == '\n') cin.get();
	getline(cin, date);

	//set the date
	stock.set_date(date);
	edit_stock(stock);

	//get the symbol
	 cout << "Symbol> ";
        if(cin.peek() == '\n') cin.get();
        getline(cin, symbol);

        //set the symbol
        stock.set_symbol(symbol);
        edit_stock(stock);

	//get the company
	 cout << "Company> ";
        if(cin.peek() == '\n') cin.get();
        getline(cin, company);

        //set the company
        stock.set_company(company);
        edit_stock(stock);

	//get the quantity
	 cout << "Quantity> ";
        if(cin.peek() == '\n') cin.get();
        file << quantity;

        //set the quantity
        stock.set_quantity(quantity);
        edit_stock(stock);

	 //get the price
         cout << "Price> ";
        if(cin.peek() == '\n') cin.get();
        file << price;

        //set the price
        stock.set_price(price);
        edit_stock(stock);

	//add the stock to portfolio
	portfolio.add(stock);
}

//sell a stock
void sell_stock(Portfolio & portfolio)
{

}

//report Current holdings
void holdings_stock(Portfolio & portfolio)
{
//display the stocks and information
        cout << stock.get_symbol() << endl;
        for(int i=0; i<stock.get_size(); i++) {
            Transaction info = stock.get_info(i);
            cout << left << setw(30) << info.get_date();
                 << setw(20) << info.get_company();
                 << info.get_quantity() << endl;
}

//report gains and losses
void gainslosses_stock(Portfolio & portfolio)
{

}

//Remove current holding
void remove_stock(Portfolio & portfolio)
{

}
