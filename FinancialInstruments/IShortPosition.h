#pragma once

#include "IUnderlying.h"

namespace FinancialInstruments
{

	__interface IShortPosition:	public IUnderlying
	{
		/**
		@brief		calculate the current value of short position underlying
		@param[in]	shortPosition		pointer to time 0 underlying short position
		@param[out]	curValue			output current value
		@return		true		successful
					false		failed
		*/
		bool CalculateCurrentValue(IShortPosition *shortPosition, Money &curValue) const;


		Money GetValue() const;
	};

}