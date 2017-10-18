

#include "stdafx.h"
#include "ShortStock.h"

#include <cassert>

#include <General.h>

namespace FinancialInstruments
{

	ShortStock::ShortStock(const Stock &stock) :
		Stock(stock),
		Position(-stock.GetPrice(stock.GetDate()))
	{}

	ShortStock::ShortStock(ShortStock &&o):
		Stock(std::move(o)),
		Position(std::move(0))
	{}

	bool ShortStock::CalculateCurrentValue(IShortPosition *shortPosition, Money &curValue) const
	{
		assert(shortPosition != nullptr);
		if (shortPosition->GetUUID() != GetUUID())
			return false;
		curValue = GetValue() - ((shortPosition != nullptr) ? shortPosition->GetValue() : 0);
		return true;
	}

	Money ShortStock::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	Money ShortStock::GetValue() const
	{
		return m_value;
	}

	const boost::gregorian::date &ShortStock::GetDate() const
	{
		return __super::GetDate();
	}

	const std::string &ShortStock::GetTicket() const
	{
		return __super::GetTicket();
	}

	const boost::uuids::uuid &ShortStock::GetUUID() const
	{
		return __super::GetUUID();
	}

}