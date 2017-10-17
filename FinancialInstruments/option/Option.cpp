

#include "stdafx.h"
#include "Option.h"

#include <cassert>


namespace FinancialInstruments
{

	Option::Option(const std::string &ticket,
		const boost::gregorian::date &date,
		const std::map<boost::gregorian::date, Money> &priceList,
		const Money &strikePrice,
		const boost::gregorian::date &expireDate):
		Underlying(ticket, date, priceList),
		m_strikePrice(strikePrice),
		m_expireDate(expireDate)
	{
		assert(strikePrice > 0);
	}

	Option::Option(const Option &o) :
		Underlying(o),
		m_strikePrice(o.m_strikePrice),
		m_expireDate(o.m_expireDate)
	{}

	Money Option::GetStrikePrice() const
	{
		return m_strikePrice;
	}

}