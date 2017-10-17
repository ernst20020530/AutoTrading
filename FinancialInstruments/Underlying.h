#pragma once

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

#include "IUnderlying.h"

#include <vector>


namespace FinancialInstruments
{

	class Underlying:	public IUnderlying
	{
	public:
		Underlying(const Underlying &o) = delete;
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;

		typedef std::map<boost::gregorian::date, Money> PriceMap;

		/**
		price from now to future.
		if the data in m_priceList matches m_date, the price is spot price.
		Otherwise it is future price
		*/
		std::unique_ptr<PriceMap>	m_priceList;
	protected:

		Underlying(const std::string &ticket,
			const boost::gregorian::date &date,
			std::unique_ptr<std::map<boost::gregorian::date, Money>> &priceList);
		Underlying(const Underlying &&o);

	private:

		const std::string				m_ticket;
		const boost::gregorian::date	m_date;
		const boost::uuids::uuid		m_uuid;

		static boost::uuids::random_generator		m_uuidGen;
	};

}