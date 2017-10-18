

#include "stdafx.h"
#include "Stock.h"

namespace FinancialInstruments
{

	Stock::Stock(const std::string &ticket,
		const boost::gregorian::date &date,
		std::unique_ptr<PricePair> &priceMap):
		Underlying(ticket, date, priceMap)
	{}

	Stock::Stock(IUnderlyingClone *underlyingClone,
		const boost::gregorian::date &date,
		std::unique_ptr<PricePair> &priceMap) :
		Underlying(underlyingClone->GetTicket(), date, priceMap, underlyingClone->GetUUID())
	{}

	Stock::Stock(const Stock &o):
		Underlying(o)
	{}

	Stock::Stock(Stock &&o):
		Underlying(std::move(o))
	{}

	std::shared_ptr<Stock> Stock::CreateLaterInstance(const boost::gregorian::date &date,
		std::unique_ptr<PricePair> &priceMap)
	{
		return std::make_shared<Stock>(static_cast<IUnderlyingClone*>(static_cast<IStock*>(this)), date, priceMap);
	}

	Money Stock::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	const boost::gregorian::date &Stock::GetDate() const
	{
		return __super::GetDate();
	}

	const std::string &Stock::GetTicket() const
	{
		return Underlying::GetTicket();
	}

	const boost::uuids::uuid &Stock::GetUUID() const
	{
		return Underlying::GetUUID();
	}

}