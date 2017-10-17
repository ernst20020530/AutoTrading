#pragma once


#include "Stock.h"
#include "IShortPosition.h"

#include <boost/functional/factory.hpp>

#include "Position.h"

namespace FinancialInstruments
{

	class ShortStock : public Stock,
		public Position,
		public IShortPosition
	{
	public:
		ShortStock(const Stock &stock);

		///interface IUnderlying
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;

		virtual Money CalculateCurrentValue(IShortPosition *longPosition) const;
		virtual Money GetValue() const;


	};

	typedef boost::factory<ShortStock*> ShortStockFactory;

}