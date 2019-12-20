//implementation of portfoilo class
#include "portfolio.h"


//constructor
Portfolio::Portfolio()
{

}

//add a stock
void Portfolio::add(const Stock & stock)
{
	stock_list.push_back(stock);
}

//getthe number of stocks
int Portfolio::get_size()
{
	return stock_list.size();
}

//get the stock index
Stock Portfolio::get_stock(int index)
{
	return stock_list[index];
}

//update the stock
void Portfolio::update_stock(int index, const Stock &stock)
{
	stock_list[index] = stock;
}

//remove a stock
void Portfolio::remove_stock(int index)
{
	stock_list.erase(stock_list.begin()+index);
}


//add buy and sell and average price
