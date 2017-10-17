#pragma once

#include "Money.h"

namespace FinancialInstruments
{

	class Position abstract
	{
	protected:
		Position(const Money &value);

		Money	m_value;
	};

}