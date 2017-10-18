#pragma once

#include <boost/uuid/random_generator.hpp>

#include "IUnderlying.h"

#include <map>


namespace FinancialInstruments
{

	typedef std::map<boost::gregorian::date, Money> PricePair;

	class Underlying:	public IUnderlying
	{
	public:
		virtual Money GetPrice(const boost::gregorian::date &date) const;
		virtual const boost::gregorian::date &GetDate() const;
		virtual const std::string &GetTicket() const;
		virtual const boost::uuids::uuid &GetUUID() const;

	protected:

		Underlying(const std::string &ticket,
			const boost::gregorian::date &date,
			std::unique_ptr<PricePair> &priceMap);
		Underlying(const std::string &ticket,
			const boost::gregorian::date &date,
			std::unique_ptr<PricePair> &priceMap,
			boost::uuids::uuid uuid);
		Underlying(const Underlying &o);
		Underlying(Underlying &&o);

	private:

		/**
		price from now to future.
		if the data in m_priceMap matches m_date, the price is spot price.
		Otherwise it is future price
		*/
		std::unique_ptr<PricePair>		m_priceMap;

		const std::string				m_ticket;
		const boost::gregorian::date	m_date;
		const boost::uuids::uuid		m_uuid;

		static boost::uuids::random_generator		m_uuidGen;
	};

}