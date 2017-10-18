

#include "stdafx.h"
#include "LongStock.h"

#include <cassert>

#include <General.h>

namespace FinancialInstruments
{

	LongStock::LongStock(const Stock &stock) :
		Stock(stock),
		Position(stock.GetPrice(stock.GetDate()))
	{}

	LongStock::LongStock(LongStock &&o):
		Stock(std::move(o)),
		Position(std::move(o))
	{}

	bool LongStock::CalculateCurrentValue(ILongPosition *longPosition, Money &curValue) const
	{
		assert(longPosition != nullptr);
		if (longPosition->GetUUID() != GetUUID())
			return false;
		curValue = GetValue() - ((longPosition != nullptr) ? longPosition->GetValue() : 0);
		return true;
	}

	Money LongStock::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	Money LongStock::GetValue() const
	{
		return m_value;
	}

	const boost::gregorian::date &LongStock::GetDate() const
	{
		return __super::GetDate();
	}

	const std::string &LongStock::GetTicket() const
	{
		return __super::GetTicket();
	}

	const boost::uuids::uuid &LongStock::GetUUID() const
	{
		return __super::GetUUID();
	}

}