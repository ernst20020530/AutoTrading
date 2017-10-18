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

#include <stock\LongStock.h>
#include <stock\ShortStock.h>

using namespace FinancialInstruments;

BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test_stock_current_and_forward_price)
{
	std::string ticket = "XLF";

	std::list<boost::gregorian::date> dateList;
	std::list<Money> priceList;

	int i = 1;
	int price = 28;
	for (; i < 20; ++i, price += 1)
	{
		dateList.push_back(boost::gregorian::date(2002, boost::date_time::Jan, i));
		priceList.push_back(Money(price));
	}

	std::unique_ptr<PricePair>	priceMap(new PricePair);

	auto it1 = dateList.begin();
	auto it2 = priceList.begin();
	while (it1 != dateList.end() && it2 != priceList.end())
		priceMap->insert(std::make_pair(*it1++, *it2++));

	std::shared_ptr<StockFactory::value_type> stock(StockFactory()(ticket, dateList.front(), priceMap));

	BOOST_TEST(stock.get() != nullptr, "Stock creation failed");

	it1 = dateList.begin();
	it2 = priceList.begin();
	while (it1 != dateList.end() && it2 != priceList.end())
		BOOST_TEST(stock->GetPrice(*it1++) == *it2++);
}

BOOST_AUTO_TEST_CASE(test_stock_current_value_mistach)
{
	std::string stockTicket1("XLF");
	boost::gregorian::date date0(2017, boost::date_time::Oct, 1);
	Money price0(24, 30);
	std::unique_ptr<PricePair>	priceMap0(new PricePair);
	priceMap0->insert(std::make_pair(date0, price0));
	std::shared_ptr<StockFactory::value_type>	stockXLF0(StockFactory()(stockTicket1, date0, priceMap0));
	BOOST_TEST(stockXLF0.get() != nullptr);
	std::shared_ptr<LongStockFactory::value_type> longStockXFL0(LongStockFactory()(*stockXLF0));



	std::string stockTicket12("XLE");
	boost::gregorian::date date1(2017, boost::date_time::Oct, 10);
	Money price1(28, 10);
	std::unique_ptr<PricePair>	priceMap1(new PricePair);
	priceMap1->insert(std::make_pair(date1, price1));
	std::shared_ptr<StockFactory::value_type>	stockXLE1(StockFactory()(stockTicket12, date1, priceMap1));
	BOOST_TEST(stockXLE1.get() != nullptr);
	std::shared_ptr<LongStockFactory::value_type> longStockXLE1(LongStockFactory()(*stockXLE1));

	Money currentValue;
	bool res = longStockXLE1->CalculateCurrentValue(longStockXFL0.get(), currentValue);
	BOOST_TEST(res == false, "test stock current value is supposed to be mismatched");
}

BOOST_AUTO_TEST_CASE(test_long_stock_gain)
{
	std::string stockTicket("XLF");
	boost::gregorian::date date0(2017, boost::date_time::Oct, 1);
	Money price0(24, 30);
	std::unique_ptr<PricePair>	priceMap0(new PricePair);
	priceMap0->insert(std::make_pair(date0, price0));
	std::shared_ptr<StockFactory::value_type>	stockXLF0(StockFactory()(stockTicket, date0, priceMap0));
	BOOST_TEST(stockXLF0.get() != nullptr);
	std::shared_ptr<LongStockFactory::value_type> longStockXFL0(LongStockFactory()(*stockXLF0));



	boost::gregorian::date date1(2017, boost::date_time::Oct, 10);
	Money price1(28, 10);
	std::unique_ptr<PricePair>	priceMap1(new PricePair);
	priceMap1->insert(std::make_pair(date1, price1));
	std::shared_ptr<StockFactory::value_type>	stockXLF1 = stockXLF0->CreateLaterInstance(date1, priceMap1);
	BOOST_TEST(stockXLF1.get() != nullptr);
	std::shared_ptr<LongStockFactory::value_type> longStockXFL1(LongStockFactory()(*stockXLF1));

	Money currentValue;
	bool res = longStockXFL1->CalculateCurrentValue(longStockXFL0.get(), currentValue);
	BOOST_TEST(res, "Long Stock gain stock type is supposed to be same");

	BOOST_TEST(currentValue == Money(3,80), "Long Stock gain current value incorrect");
}

BOOST_AUTO_TEST_CASE(test_long_stock_loss)
{
	std::string stockTicket("XLF");
	boost::gregorian::date date0(2017, boost::date_time::Oct, 1);
	Money price0(24, 30);
	std::unique_ptr<PricePair> priceMap0(new PricePair);
	priceMap0->insert(std::make_pair(date0, price0));
	std::shared_ptr<StockFactory::value_type>	stockXLF0(StockFactory()(stockTicket, date0, priceMap0));
	BOOST_TEST(stockXLF0.get() != nullptr);
	std::shared_ptr<LongStockFactory::value_type> longStockXFL0(LongStockFactory()(*stockXLF0));



	boost::gregorian::date date1(2017, boost::date_time::Oct, 10);
	Money price1(21);
	std::unique_ptr<PricePair> priceMap1(new PricePair);
	priceMap1->insert(std::make_pair(date1, price1));
	std::shared_ptr<StockFactory::value_type>	stockXLF1 = stockXLF0->CreateLaterInstance(date1, priceMap1);
	BOOST_TEST(stockXLF1.get() != nullptr);
	std::shared_ptr<LongStockFactory::value_type> longStockXFL1(LongStockFactory()(*stockXLF1));

	Money currentValue;
	bool res = longStockXFL1->CalculateCurrentValue(longStockXFL0.get(), currentValue);
	BOOST_TEST(res, "Long Stock loss stock type is supposed to be same");

	BOOST_TEST(currentValue == Money(-3, -30), "Long Stock loss current value incorrect");
}

BOOST_AUTO_TEST_CASE(test_short_stock_gain)
{
	std::string stockTicket("XLF");
	boost::gregorian::date date0(2017, boost::date_time::Oct, 1);
	Money price0(24, 30);
	std::unique_ptr<PricePair> priceMap0(new PricePair);
	priceMap0->insert(std::make_pair(date0, price0));
	std::shared_ptr<StockFactory::value_type>	stockXLF0(StockFactory()(stockTicket, date0, priceMap0));
	BOOST_TEST(stockXLF0.get() != nullptr);
	std::shared_ptr<ShortStockFactory::value_type> shortStockXFL0(ShortStockFactory()(*stockXLF0));



	boost::gregorian::date date1(2017, boost::date_time::Oct, 10);
	Money price1(28, 10);
	std::unique_ptr<PricePair> priceMap1(new PricePair);
	priceMap1->insert(std::make_pair(date1, price1));
	std::shared_ptr<StockFactory::value_type>	stockXLF1 = stockXLF0->CreateLaterInstance(date1, priceMap1);
	BOOST_TEST(stockXLF1.get() != nullptr);
	std::shared_ptr<ShortStockFactory::value_type> shortStockXFL1(ShortStockFactory()(*stockXLF1));

	Money currentValue;
	bool res = shortStockXFL1->CalculateCurrentValue(shortStockXFL0.get(), currentValue);
	BOOST_TEST(res, "Short Stock gain stock type is supposed to be same");

	BOOST_TEST(currentValue == Money(-3, -80), "Short Stock gain current value incorrect");
}

BOOST_AUTO_TEST_CASE(test_short_stock_loss)
{
	std::string stockTicket("XLF");
	boost::gregorian::date date0(2017, boost::date_time::Oct, 1);
	Money price0(24, 30);
	std::unique_ptr<PricePair> priceMap0(new PricePair);
	priceMap0->insert(std::make_pair(date0, price0));
	std::shared_ptr<StockFactory::value_type>	stockXLF0(StockFactory()(stockTicket, date0, priceMap0));
	BOOST_TEST(stockXLF0.get() != nullptr);
	std::shared_ptr<ShortStockFactory::value_type> shortStockXFL0(ShortStockFactory()(*stockXLF0));



	boost::gregorian::date date1(2017, boost::date_time::Oct, 10);
	Money price1(21);
	std::unique_ptr<PricePair> priceMap1(new PricePair);
	priceMap1->insert(std::make_pair(date1, price1));
	std::shared_ptr<StockFactory::value_type>	stockXLF1 = stockXLF0->CreateLaterInstance(date1, priceMap1);
	BOOST_TEST(stockXLF1.get() != nullptr);
	std::shared_ptr<ShortStockFactory::value_type> shortStockXFL1(ShortStockFactory()(*stockXLF1));

	Money currentValue;
	bool res = shortStockXFL1->CalculateCurrentValue(shortStockXFL0.get(), currentValue);
	BOOST_TEST(res, "Short Stock loss stock type is supposed to be same");

	BOOST_TEST(currentValue == Money(3, 30), "Short Stock loss current value incorrect");
}




BOOST_AUTO_TEST_SUITE_END()


