#pragma once

#include "Option.h"

namespace FinancialInstruments
{

	class CallOption abstract:	public Option
	{
	public:
		CallOption(const std::string &ticket,
			const boost::gregorian::date &date,
			std::unique_ptr<PricePair> &priceMap,
			const Money &strikePrice,
			const boost::gregorian::date &expireDate);
		CallOption(const CallOption &o);
		CallOption(CallOption &&o);
		const CallOption &operator = (const CallOption &o) = delete;

	protected:

		//virtual double CalculateMaxProfit(IUnderlying *underlying) const;
		//virtual double CalculateRealizedPremium(IUnderlying *underlying) const;
		//virtual double CalculateMaxProfitPerS0Ratio(IUnderlying *underlying) const;
		//virtual double CalculateRPperS0Ratio(IUnderlying *underlying) const;
	};

}