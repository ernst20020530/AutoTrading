
#include "stdafx.h"
#include "LongCallOption.h"
#include <cassert>
#include <algorithm>

#include "IStock.h"

namespace FinancialInstruments
{

	LongCallOption::LongCallOption(const CallOption &callOption,
		IStock *stock):
		CallOption(callOption),
		Position(callOption.GetPrice(callOption.GetDate()))
	{
		assert(stock != nullptr);
	}

	double LongCallOption::CalculateCurrentValue(ILongPosition *longPosition)
	{
		assert(longPosition != nullptr);
		return GetValue() - (longPosition != nullptr) ? longPosition->GetValue() : 0;
	}

	double LongCallOption::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	double LongCallOption::GetValue() const
	{
		return m_value;
	}

	const boost::gregorian::date &LongCallOption::GetDate() const
	{
		return __super::GetDate();
	}

	const std::string &LongCallOption::GetTicket() const
	{
		return __super::GetTicket();
	}

}