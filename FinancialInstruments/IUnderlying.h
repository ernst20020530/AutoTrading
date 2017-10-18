#pragma once

#include <boost/date_time/gregorian/greg_date.hpp>

#include "IUnderlyingClone.h"
#include "Money.h"

namespace FinancialInstruments
{

	__interface IUnderlying:	public IUnderlyingClone
	{
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
	};

}