

#include "stdafx.h"

#include "TerminalOutput.h"

#include <iostream>

void TerminalOutput::ProcessPrintInfo(std::string &info)
{
	InfoOutput::ProcessPrintInfo(info);
	std::cout << info;
}

void TerminalOutput::ProcessPrintError(std::string &error)
{
	InfoOutput::ProcessPrintError(error);
	std::cout << error;
}

void TerminalOutput::ProcessPrintWarning(std::string &warn)
{
	InfoOutput::ProcessPrintWarning(warn);
	std::cout << warn;
}