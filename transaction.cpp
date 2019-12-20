//the implementation of the transaction class
#include <vector>
#include "transaction.h"

//constructors
Transaction::Transaction()
{
	//blank
}

Transaction::Transaction(const std::string &date, const std::string &company, const int &quantity, const double &price)
{
	this->date = date;

	this->company = company;

	this->quantity = quantity;

	this->price = price;
}

//get the date
std::string Transaction::get_date()
{
	return date;
}

//get the company name
std::string Transaction::get_company()
{
	return company;
}

//get the quantity
int Transaction::get_quantity()
{
	return quantity;
}

//get the price
double Transaction::get_price()
{
	return price;
}

//set the date
void Transaction::set_date(const std::string & date)
{
	this->date = date;
}

//set the company
void Transaction::set_company(const std::string & company)
{
	this->company = company;
}

//set the quantity
void Transaction::set_quantity(const int & quantity)
{
	this->quantity = quantity;
}
//set the price
void Transaction::set_price(const double & price)
{
	this->price = price;
}
