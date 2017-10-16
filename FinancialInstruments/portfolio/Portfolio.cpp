

#include "stdafx.h"
#include "Portfolio.h"

#include <numeric>
#include <cassert>

#include "ILongPosition.h"
#include "IShortPosition.h"

namespace FinancialInstruments
{

	Portfolio::Portfolio(std::unique_ptr<boost::gregorian::date> &date):
		m_date(std::move(date)),
		m_longPositionList(new std::list<std::shared_ptr<ILongPosition>>()),
		m_shortPositionList(new std::list<std::shared_ptr<IShortPosition>>())
	{}

	Portfolio::Portfolio(Portfolio &&o):
		m_date(std::move(o.m_date)),
		m_longPositionList(std::move(o.m_longPositionList)),
		m_shortPositionList(std::move(o.m_shortPositionList))
	{}

	void Portfolio::AddLongPosition(std::shared_ptr<ILongPosition> &longPosition)
	{
		assert(longPosition.get() != nullptr);
		assert(TicketIsAdded(longPosition.get()));
		assert(m_longPositionList.get() != nullptr);
		m_longPositionList->push_back(longPosition);
	}

	void Portfolio::AddShortPosition(std::shared_ptr<IShortPosition> &shortPosition)
	{
		assert(shortPosition.get() != nullptr);
		assert(TicketIsAdded(shortPosition.get()));
		assert(m_shortPositionList.get() != nullptr);
		m_shortPositionList->push_back(shortPosition);
	}

	double Portfolio::CalculateValue() const
	{
		double value = 0;

		assert(m_longPositionList.get() != nullptr);
		value = std::accumulate(m_longPositionList->begin(), m_longPositionList->end(), value, [](auto v, auto it) {return v + it->GetValue(); });

		assert(m_shortPositionList.get() != nullptr);
		return std::accumulate(m_shortPositionList->begin(), m_shortPositionList->end(), value, [](auto v, auto it) {return v + it->GetValue(); });
	}

	double Portfolio::CalculateCurrentValue(const Portfolio& portfolio) const
	{
		return CalculateValue() - portfolio.CalculateValue();
	}

	bool Portfolio::TicketIsAdded(ILongPosition *longPosition) const
	{
		assert(longPosition != nullptr);
		assert(m_longPositionList.get() != nullptr);
		return std::any_of(m_longPositionList->begin(),m_longPositionList->end(), [=](auto it) { return longPosition->GetTicket() == it->GetTicket(); });
	}

	bool Portfolio::TicketIsAdded(IShortPosition *shortPosition) const
	{
		assert(shortPosition != nullptr);
		assert(m_shortPositionList.get() != nullptr);
		return std::any_of(m_shortPositionList->begin(), m_shortPositionList->end(), [=](auto it) { return shortPosition->GetTicket() == it->GetTicket(); });
	}

}