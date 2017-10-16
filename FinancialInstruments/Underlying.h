#pragma once

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

#include "IUnderlying.h"


namespace FinancialInstruments
{

	class Underlying:	public IUnderlying
	{
	public:
		virtual double GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;

	protected:

		Underlying(const std::string &ticket,
			const boost::gregorian::date &date,
			const std::map<boost::gregorian::date, double> &priceList);

	private:

		const std::string				m_ticket;
		const boost::gregorian::date	m_date;
		const boost::uuids::uuid		m_uuid;

		/**
		price from now to future.
		if the data in m_priceList matches m_date, the price is spot price.
		Otherwise it is future price
		*/
		std::map<boost::gregorian::date, double>	m_priceList;

		static boost::uuids::random_generator		m_uuidGen;
	};

}