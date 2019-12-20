//class definition for the transaction class
#ifndef TRANSACTION_H
#define TRANSACTION_H


#include <string>
#include <vector>

class Transaction
{
public:
	//constructors
	Transaction();
	Transaction(const std::string &date, const std::string &company, const int &quantity, const double &price);

	//get the date
	std::string get_date();

	//get the company
	std::string get_company();

	//get the quantity
	int get_quantity();

	//get the price
	double get_price();

	//set the date
	void set_date(const std::string & date);

	//set the company
	void set_company(const std::string & company);

	//set the quantity
	void set_quantity(const int & quantity);

	//set the price
	void set_price(const double & price);

private:
	//the date
	std::string date;

	//the company
	std::string company;

	//the quantity
	int quantity;

	//the price
	double price;
};
#endif
