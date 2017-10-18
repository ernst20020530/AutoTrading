#pragma once

#include <string>

#include <boost/date_time/gregorian/gregorian.hpp>

#include "Underlying.h"

namespace FinancialInstruments
{

	class Option abstract:	public Underlying
	{
	public:
		Option(Option &&o);

		const Option &operator = (const Option &o) = delete;

		Money GetStrikePrice() const;

	protected:
		Option(const std::string &ticket,
			const boost::gregorian::date &date,
			std::unique_ptr<PricePair> &priceMap,
			const Money &strikePrice,
			const boost::gregorian::date &expireDate);
		Option(const Option &o);

		const Money	m_strikePrice;
		const boost::gregorian::date	m_expireDate;

	};

	

}