// FinancialInstrumentsUnitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"
#include <list>
#include <algorithm>
#include <thread>
#include <cstdio>
#include <memory>

#define BOOST_TEST_MODULE example
#include <boost\test\included\unit_test.hpp>
#include <boost\test\data\test_case.hpp>

typedef std::list<std::pair<int, int>> SingleUnit;
typedef std::list<SingleUnit> MultiUnit;

#include <stock\Stock.h>

using namespace FinancialInstruments;

BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test_stock_current_and_forward_price)
{
	std::string ticket = "XLF";

	std::list<boost::gregorian::date> dateList;
	std::list<double> priceList;

	int i = 1;
	double price = 28;
	for (; i < 20; ++i, price += 0.5)
	{
		dateList.push_back(boost::gregorian::date(2002, boost::date_time::Jan, i));
		priceList.push_back(price);
	}

	std::map<boost::gregorian::date, double> priceMap;

	auto it1 = dateList.begin();
	auto it2 = priceList.begin();
	while (it1 != dateList.end() && it2 != priceList.end())
		priceMap.insert(std::make_pair(*it1++, *it2++));

	std::shared_ptr<Stock> stock = Stock::CreateInstance(ticket, dateList.front(), priceMap);

	BOOST_TEST(stock.get() != nullptr, "Stock creation failed");

	it1 = dateList.begin();
	it2 = priceList.begin();
	while (it1 != dateList.end() && it2 != priceList.end())
		BOOST_TEST(stock->GetPrice(*it1++) == *it2++);
}


BOOST_AUTO_TEST_CASE(test_stock_current_value)
{
	std::string stockTicket("XLF");
	boost::gregorian::date date0(2017, boost::date_time::Oct, 1);
	double price0 = 24.3;
	std::map<boost::gregorian::date, double> priceMap0;
	priceMap0.insert(std::make_pair(date0, price0));
	std::shared_ptr<Stock>	stockXLF = Stock::CreateInstance(stockTicket, date0, priceMap0);


}


BOOST_AUTO_TEST_SUITE_END()


