
#include "stdafx.h"
#include "Underlying.h"


namespace FinancialInstruments
{

	boost::uuids::random_generator Underlying::m_uuidGen = boost::uuids::random_generator();

	Underlying::Underlying(const std::string &ticket,
		const boost::gregorian::date &date,
		std::unique_ptr<PricePair> &priceMap):
		m_ticket(ticket),
		m_date(date),
		m_priceMap(std::move(priceMap)),
		m_uuid(m_uuidGen())
	{}


	Underlying::Underlying(const std::string &ticket,
		const boost::gregorian::date &date,
		std::unique_ptr<PricePair> &priceMap,
		boost::uuids::uuid uuid) :
		m_ticket(ticket),
		m_date(date),
		m_priceMap(std::move(priceMap)),
		m_uuid(uuid)
	{}

	Underlying::Underlying(const Underlying &o):
		m_ticket(o.m_ticket),
		m_date(o.m_date),
		m_priceMap(new PricePair(o.m_priceMap->begin(), o.m_priceMap->end())),
		m_uuid(o.m_uuid)
	{}

	Underlying::Underlying(Underlying &&o):
		m_ticket(o.m_ticket),
		m_date(o.m_date),
		m_priceMap(std::move(o.m_priceMap)),
		m_uuid(o.m_uuid)
	{}


	Money Underlying::GetPrice(const boost::gregorian::date &date) const
	{
		assert(m_priceMap.get() != nullptr);
		auto it = m_priceMap->find(date);
		return it != m_priceMap->end() ? it->second : Money();
	}

	const boost::gregorian::date &Underlying::GetDate() const
	{
		return m_date;
	}

	const std::string &Underlying::GetTicket() const
	{
		return m_ticket;
	}

	const boost::uuids::uuid &Underlying::GetUUID() const
	{
		return m_uuid;
	}

}