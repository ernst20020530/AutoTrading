#pragma once

#include "CallOption.h"
#include "Position.h"
#include "IShortPosition.h"


namespace FinancialInstruments
{

	__interface IStock;

	class ShortCallOption:	public CallOption,
		public Position,
		public IShortPosition
	{
	public:
		ShortCallOption(const CallOption &callOption,
			IStock *stock);

		///interface IShortPosition
		virtual double CalculateCurrentValue(IShortPosition *shortPosition);
		virtual double GetValue() const;

		///interface IUnderlying
		virtual double GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;

	};

}