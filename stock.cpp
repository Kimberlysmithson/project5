//implementation of the stock class
#include <vector>
#include "stock.h"
#include "transaction.h"

//constructors
Stock::Stock()
{

}

Stock::Stock(std::string symbol)
{
	this->symbol = symbol;
}

//add information about the stock
void Stock::add(const Transaction & info)
{
	this-> info.push_back(info);
}

//get the symbol of the stock
std::string Stock::get_symbol()
{
	return symbol;
}

//set the symbol of the stock
void Stock::set_symbol(const std::string & name)
{
	this->symbol = symbol;
}

//return the number of items in the stock
int Stock::get_size()
{
	return info.size();
}

//return the indexed stock info
Transaction Stock::get_info(int index)
{
	return info[index];
}

//update stock info
void Stock::update_info(int index, const Transaction & info)
{
	this->info[index] = info;
}

//remove the stock info
void Stock::remove_info(int index)
{
	info.erase(info.begin() + index);
}

