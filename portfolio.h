//class definition for portfolioclass
#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include <string>
#include <vector>
#include "stock.h"

class Portfolio
{
public:
    //constructor
    Portfolio();

    //add a stock
    void add(const Stock& stock);

    //get the number of stock

    int get_size();

    //get the stock at the index
    Stock get_stock(int index);

    //update the stock
    void update_stock(int index, const Stock& stock);

    //remove a stock
    void remove_stock(int index);

private:
    //list of stocks
    std::vector<Stock> stock_list;
};
#endif

