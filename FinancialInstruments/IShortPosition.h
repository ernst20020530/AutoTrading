#pragma once

#include "IUnderlying.h"

namespace FinancialInstruments
{

	__interface IShortPosition:	public IUnderlying
	{
		/**
		@brief		calculate the current value of short position underlying
		@param[in]	shortPosition		pointer to time 0 underlying short position
		*/
		double CalculateCurrentValue(IShortPosition *shortPosition) const;


		double GetValue();
	};

}