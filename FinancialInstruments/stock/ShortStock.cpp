

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

	Money ShortStock::CalculateCurrentValue(IShortPosition *shortPosition) const
	{
		assert(shortPosition != nullptr);
		return GetValue() - ((shortPosition != nullptr) ? shortPosition->GetValue() : 0);
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

}