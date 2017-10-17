#pragma once

#include "Stock.h"
#include "ILongPosition.h"

#include <boost/functional/factory.hpp>

#include "Position.h"

namespace FinancialInstruments
{

	class LongStock:	public Stock,
		public Position,
		public ILongPosition
	{
	public:
		LongStock(const Stock &stock);

		///interface IUnderlying
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;

		virtual Money CalculateCurrentValue(ILongPosition *longPosition) const;
		virtual Money GetValue() const;


	};

	typedef boost::factory<LongStock*> LongStockFactory;

}