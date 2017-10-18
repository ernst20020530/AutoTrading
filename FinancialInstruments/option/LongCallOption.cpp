
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

	LongCallOption::LongCallOption(LongCallOption &&o):
		CallOption(std::move(o)),
		Position(std::move(o))
	{}

	bool LongCallOption::CalculateCurrentValue(ILongPosition *longPosition, Money &curValue) const
	{
		assert(longPosition != nullptr);
		if (longPosition->GetUUID() != GetUUID())
			return false;
		curValue = GetValue() - ((longPosition != nullptr) ? longPosition->GetValue() : 0);
		return true;
	}

	Money LongCallOption::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	Money LongCallOption::GetValue() const
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

	const boost::uuids::uuid &LongCallOption::GetUUID() const
	{
		return __super::GetUUID();
	}

}