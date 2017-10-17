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
		virtual Money CalculateCurrentValue(ILongPosition *longPosition);
		virtual Money GetValue() const;

		///interface IUnderlying
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const; 
		virtual const std::string &GetTicket() const;

	};

}