#pragma once

#include "InfoOutput.h"

#include "Singleton.h"

class TerminalOutput:	public InfoOutput
{
protected:
	virtual void ProcessPrintInfo(std::string &info);
	virtual void ProcessPrintError(std::string &error);
	virtual void ProcessPrintWarning(std::string &warn);
};

typedef Singleton<TerminalOutput> TerminalOutputSingleton;