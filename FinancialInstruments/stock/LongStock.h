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
		LongStock(const LongStock &o) = delete;
		LongStock(LongStock &&o);

		///interface IUnderlying
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;
		virtual const boost::uuids::uuid &GetUUID() const;

		virtual bool CalculateCurrentValue(ILongPosition *longPosition, Money &curValue) const;
		virtual Money GetValue() const;


	};

	typedef boost::factory<LongStock*> LongStockFactory;

}