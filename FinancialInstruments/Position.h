#pragma once


namespace FinancialInstruments
{

	class Position abstract
	{
	protected:
		Position(double value);

		double	m_value;
	};

}