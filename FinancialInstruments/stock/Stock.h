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
			std::unique_ptr<PricePair> &priceMap);
		Stock(IUnderlyingClone *underlyingClone,
			const boost::gregorian::date &date,
			std::unique_ptr<PricePair> &priceMap);
		Stock(Stock &&o);

		virtual std::shared_ptr<Stock> CreateLaterInstance(const boost::gregorian::date &date,
			std::unique_ptr<PricePair> &priceMap);

		///interface IUnderlying
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;
		virtual const boost::uuids::uuid &GetUUID() const;

	protected:
		Stock(const Stock &o);

	private:

	};

	typedef boost::factory<Stock*> StockFactory;

}