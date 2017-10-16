#pragma once

#include "CallOption.h"
#include "Position.h"
#include "ILongPosition.h"


namespace FinancialInstruments
{

	__interface IStock;

	class LongCallOption:	public CallOption,
		public Position,
		public ILongPosition
	{
	public:
		LongCallOption(const CallOption &callOption,
			IStock *stock);

		///interface ILongPosition
		virtual double CalculateCurrentValue(ILongPosition *longPosition);
		virtual double GetValue() const;

		///interface IUnderlying
		virtual double GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const; 
		virtual const std::string &GetTicket() const;

	};

}