#pragma once

#include "Stock.h"
#include "ILongPosition.h"

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
		virtual double GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;

	protected:

		virtual double CalculateCurrentValue(ILongPosition *longPosition) const;
		virtual double GetValue() const;


	};

}