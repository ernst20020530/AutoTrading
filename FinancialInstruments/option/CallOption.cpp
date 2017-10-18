
#include "stdafx.h"
#include "CallOption.h"

#include <cassert>
#include <algorithm>

#include "IUnderlying.h"

namespace FinancialInstruments
{

	CallOption::CallOption(const std::string &ticket,
		const boost::gregorian::date &date,
		std::unique_ptr<PricePair> &priceMap,
		const Money &strikePrice,
		const boost::gregorian::date &expireDate):
		Option(ticket, date, priceMap, strikePrice, expireDate)
	{}

	CallOption::CallOption(const CallOption &o) :
		Option(o)
	{}

	CallOption::CallOption(CallOption &&o):
		Option(std::move(o))
	{}

	//double CallOption::CalculateMaxProfit(IUnderlying *underlying) const
	//{
	//	assert(underlying != nullptr);
	//	double underlyingSpotPrice = underlying->GetPrice(m_date);
	//	assert(underlyingSpotPrice > 0);

	//	return m_strikePrice - underlyingSpotPrice + m_premium;
	//}

	//double CallOption::CalculateRealizedPremium(IUnderlying *underlying) const
	//{
	//	return std::min(m_premium, CalculateMaxProfit(underlying));
	//}

	//double CallOption::CalculateMaxProfitPerS0Ratio(IUnderlying *underlying) const
	//{
	//	assert(underlying != nullptr);
	//	double underlyingSpotPrice = underlying->GetPrice(m_date);
	//	assert(underlyingSpotPrice > 0);

	//	return CalculateMaxProfit(underlying) / underlyingSpotPrice;
	//}

	//double CallOption::CalculateRPperS0Ratio(IUnderlying *underlying) const
	//{
	//	assert(underlying != nullptr);
	//	double underlyingSpotPrice = underlying->GetPrice(m_date);
	//	assert(underlyingSpotPrice > 0);

	//	return CalculateRealizedPremium(underlying) / underlyingSpotPrice;
	//}
}