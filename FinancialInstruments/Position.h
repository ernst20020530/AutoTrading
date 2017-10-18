#pragma once

#include "Money.h"

namespace FinancialInstruments
{

	class Position abstract
	{
	protected:
		Position(const Money &value);
		Position(const Position &o);
		Position(Position &&o);

		Money	m_value;
	};

}