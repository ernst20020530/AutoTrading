#pragma once

#include "IUnderlying.h"

namespace FinancialInstruments
{

	__interface ILongPosition : public IUnderlying
	{
		Money CalculateCurrentValue(ILongPosition *longPosition) const;


		Money GetValue() const;

		//double CalculateMaxProfit(IUnderlying *underlying) const;
		//double CalculateRealizedPremium(IUnderlying *underlying) const;
		//double CalculateMaxProfitPerS0Ratio(IUnderlying *underlying) const;
		//double CalculateRPperS0Ratio(IUnderlying *underlying) const;
	};


}