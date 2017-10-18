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
		ShortCallOption(ShortCallOption &&o);

		///interface IShortPosition
		virtual bool CalculateCurrentValue(IShortPosition *shortPosition, Money &curValue) const;
		virtual Money GetValue() const;

		///interface IUnderlying
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;
		virtual const boost::uuids::uuid &GetUUID() const;

	};

}