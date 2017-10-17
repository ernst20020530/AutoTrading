
#include "stdafx.h"
#include "Underlying.h"


namespace FinancialInstruments
{

	boost::uuids::random_generator Underlying::m_uuidGen = boost::uuids::random_generator();

	Underlying::Underlying(const std::string &ticket,
		const boost::gregorian::date &date,
		std::unique_ptr<std::map<boost::gregorian::date, Money>> &priceList):
		m_ticket(ticket),
		m_date(date),
		m_priceList(std::move(priceList)),
		m_uuid(m_uuidGen())
	{}

	Underlying::Underlying(const Underlying &&o):
		m_ticket(o.m_ticket),
		m_date(o.m_date),
		m_priceList(),
		m_uuid(o.m_uuid)
	{
		m_priceList->insert(std::move_iterator<PriceMap::iterator>(o.m_priceList->begin()),
			std::move_iterator<PriceMap::iterator>(o.m_priceList->end()));
	}


	Money Underlying::GetPrice(const boost::gregorian::date &date) const
	{
		assert(m_priceList.get() != nullptr);
		auto it = m_priceList->find(date);
		return it != m_priceList->end() ? it->second : Money();
	}

	const boost::gregorian::date &Underlying::GetDate() const
	{
		return m_date;
	}

	const std::string &Underlying::GetTicket() const
	{
		return m_ticket;
	}

}