

#include "stdafx.h"
#include "Stock.h"

namespace FinancialInstruments
{

	std::shared_ptr<Stock> Stock::CreateInstance(const std::string &ticket,
		const boost::gregorian::date &date,
		const std::map<boost::gregorian::date, double> &priceList)
	{
		return std::make_shared<Stock>(ticket, date, priceList);
	}

	Stock::Stock(const std::string &ticket,
		const boost::gregorian::date &date,
		const std::map<boost::gregorian::date, double> &priceList):
		Underlying(ticket, date, priceList)
	{}

	Stock::Stock(const Stock &o):
		Underlying(o)
	{}

	std::shared_ptr<Stock> Stock::CreateLaterInstance(const boost::gregorian::date &date,
		const std::map<boost::gregorian::date, double> &priceList)
	{
		return std::make_shared<Stock>(GetTicket(), date, priceList);
	}

	double Stock::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	const boost::gregorian::date &Stock::GetDate() const
	{
		return __super::GetDate();
	}

	const std::string &Stock::GetTicket() const
	{
		return __super::GetTicket();
	}

}