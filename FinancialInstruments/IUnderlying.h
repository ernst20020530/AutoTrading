#pragma once

#include <boost/date_time/gregorian/greg_date.hpp>
#include <string>

namespace FinancialInstruments
{

	__interface IUnderlying
	{
		virtual double GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;
	};

}