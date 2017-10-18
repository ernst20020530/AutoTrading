
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

	ShortCallOption::ShortCallOption(ShortCallOption &&o):
		CallOption(std::move(o)),
		Position(std::move(0))
	{}

	bool ShortCallOption::CalculateCurrentValue(IShortPosition *shortPosition, Money &curValue) const
	{
		assert(shortPosition != nullptr);
		if (shortPosition->GetUUID() != GetUUID())
			return false;
		curValue = GetValue() - ((shortPosition != nullptr) ? shortPosition->GetValue() : 0);
		return true;
	}

	Money ShortCallOption::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	Money ShortCallOption::GetValue() const
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

	const boost::uuids::uuid &ShortCallOption::GetUUID() const
	{
		return __super::GetUUID();
	}

}