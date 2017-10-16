

#include "stdafx.h"
#include "LongStock.h"

#include <cassert>

namespace FinancialInstruments
{

	LongStock::LongStock(const Stock &stock) :
		Stock(stock),
		Position(stock.GetPrice(stock.GetDate()))
	{}

	double LongStock::CalculateCurrentValue(ILongPosition *longPosition) const
	{
		assert(longPosition != nullptr);
		return GetValue() - (longPosition != nullptr) ? longPosition->GetValue() : 0;
	}

	double LongStock::GetPrice(const boost::gregorian::date &date) const
	{
		return __super::GetPrice(date);
	}

	double LongStock::GetValue() const
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

}