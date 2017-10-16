#pragma once

#include <string>
#include <map>

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
			const std::map<boost::gregorian::date, double> &priceList);
		Stock(const Stock &o);
		Stock(Stock &&o) = delete;

		static std::shared_ptr<Stock> CreateInstance(const std::string &ticket,
			const boost::gregorian::date &date,
			const std::map<boost::gregorian::date, double> &priceList);

		virtual std::shared_ptr<Stock> CreateLaterInstance(const boost::gregorian::date &date,
			const std::map<boost::gregorian::date, double> &priceList);

		///interface IUnderlying
		virtual double GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;


	};

}