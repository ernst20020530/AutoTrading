#pragma once

#include <boost/date_time/gregorian/greg_date.hpp>
#include <string>

#include "Money.h"

namespace FinancialInstruments
{

	__interface IUnderlying
	{
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;
	};

}