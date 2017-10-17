#pragma once

#include "Option.h"

namespace FinancialInstruments
{

	class CallOption abstract:	public Option
	{
	public:
		CallOption(const std::string &ticket,
			const boost::gregorian::date &date,
			const std::map<boost::gregorian::date, Money> &priceList,
			const Money &strikePrice,
			const boost::gregorian::date &expireDate);
		CallOption(const CallOption &o);
		CallOption(CallOption &&o) = delete;
		const CallOption &operator = (const CallOption &o) = delete;

	protected:

		//virtual double CalculateMaxProfit(IUnderlying *underlying) const;
		//virtual double CalculateRealizedPremium(IUnderlying *underlying) const;
		//virtual double CalculateMaxProfitPerS0Ratio(IUnderlying *underlying) const;
		//virtual double CalculateRPperS0Ratio(IUnderlying *underlying) const;
	};

}