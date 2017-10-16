
#include "stdafx.h"
#include "ShortCallOption.h"
#include <cassert>
#include <algorithm>

#include "IStock.h"

namespace FinancialInstruments
{

	ShortCallOption::ShortCallOption(const CallOption &callOption,
		IStock *stock):
		CallOption(callOption),
		Position(callOption.GetPrice(callOption.GetDate()))
	{
		assert(stock != nullptr);
	}

	double ShortCallOption::CalculateCurrentValue(IShortPosition *shortPosition)
	{
		assert(shortPosition != nullptr);
		return GetValue() - (shortPosition != nullptr) ? shortPosition->GetValue() : 0;
	}

	double ShortCallOption::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	double ShortCallOption::GetValue() const
	{
		return m_value;
	}

	const boost::gregorian::date &ShortCallOption::GetDate() const
	{
		return __super::GetDate();
	}

	const std::string &ShortCallOption::GetTicket() const
	{
		return __super::GetTicket();
	}

}