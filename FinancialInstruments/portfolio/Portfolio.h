#pragma once

#include <list>
#include <memory>

#include <boost/date_time/gregorian/greg_date.hpp>

#include "Money.h"

namespace FinancialInstruments
{

	__interface ILongPosition;
	__interface IShortPosition;
	__interface IUnderlying;

	class Portfolio
	{
	public:
		Portfolio(std::unique_ptr<boost::gregorian::date> &date);
		Portfolio(const Portfolio &o) = delete;
		Portfolio(Portfolio &&o);

		Portfolio &operator = (const Portfolio &o) = delete;

		void AddLongPosition(std::shared_ptr<ILongPosition> &longPosition);
		void AddShortPosition(std::shared_ptr<IShortPosition> &shortPosition);

		Money CalculateValue() const;
		Money CalculateCurrentValue(const Portfolio& portfolio) const;


	private:

		bool TicketIsAdded(ILongPosition *longPosition) const;
		bool TicketIsAdded(IShortPosition *shortPosition) const;

		std::unique_ptr<boost::gregorian::date>							m_date;
		std::unique_ptr<std::list<std::shared_ptr<ILongPosition>>>		m_longPositionList;
		std::unique_ptr<std::list<std::shared_ptr<IShortPosition>>>		m_shortPositionList;

	};

}