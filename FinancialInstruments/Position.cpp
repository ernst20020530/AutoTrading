

#include "stdafx.h"
#include "Position.h"


namespace FinancialInstruments
{

	Position::Position(const Money &value):
		m_value(value)
	{}

	Position::Position(const Position &o):
		m_value(o.m_value)
	{}

	Position::Position(Position &&o) :
		m_value(o.m_value)
	{}
}