//class definition for the stock class
#ifndef STOCK_H
#define STOCK_H


#include <string>
#include <vector>
#include "transaction.h"

class Stock
{
public:
	//constructors
	Stock();
	Stock(std::string symbol);

	//add information to the stock
	void add(const Transaction& info);

	//get the symbol of the stock
	std::string get_symbol();

 	//set the name of the stock
	void set_symbol(const std::string& symbol);

	//return the number of info items in the stock
	int get_size();

	//return the indexed stock info (indexed from 0)
	Transaction get_info(int index);

	//change stock info
	void update_info(int index, const Transaction& info);

	//remove the stock info
	void remove_info(int index);

private:
	//the stock information
	std::vector<Transaction>  info;

	//the symbol for thestock
	std::string symbol;
};

#endif
