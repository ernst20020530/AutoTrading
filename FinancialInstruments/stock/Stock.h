#pragma once

#include <string>
#include <map>

#include <boost/functional/factory.hpp>

#include "Underlying.h"
#include "IStock.h"

namespace FinancialInstruments
{

	class Stock:	public Underlying,
		public IStock
	{
	public:
		Stock(const std::string &ticket,
			const boost::gregorian::date &date,
			const std::map<boost::gregorian::date, Money> &priceList);
		Stock(const Stock &o);
		Stock(Stock &&o) = delete;

		virtual std::shared_ptr<Stock> CreateLaterInstance(const boost::gregorian::date &date,
			const std::map<boost::gregorian::date, Money> &priceList);

		///interface IUnderlying
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;

	};

	typedef boost::factory<Stock*> StockFactory;

}