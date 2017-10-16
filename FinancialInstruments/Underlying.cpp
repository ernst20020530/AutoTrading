
#include "stdafx.h"
#include "Underlying.h"


namespace FinancialInstruments
{

	boost::uuids::random_generator Underlying::m_uuidGen = boost::uuids::random_generator();

	Underlying::Underlying(const std::string &ticket,
		const boost::gregorian::date &date,
		const std::map<boost::gregorian::date, double> &priceList):
		m_ticket(ticket),
		m_date(date),
		m_priceList(priceList),
		m_uuid(m_uuidGen())
	{}

	double Underlying::GetPrice(const boost::gregorian::date &date) const
	{
		auto it = m_priceList.find(date);
		return it != m_priceList.end() ? it->second : -1;
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