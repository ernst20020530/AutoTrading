#pragma once

#include "InfoOutput.h"

#include <fstream>

#include "Singleton.h"

class FileOutput:	public InfoOutput
{
public:
	FileOutput();
	virtual ~FileOutput();

protected:
	virtual void ProcessPrintInfo(std::string &info);
	virtual void ProcessPrintError(std::string &error);
	virtual void ProcessPrintWarning(std::string &warn);

private:

	std::ofstream	m_file;
};

typedef Singleton<FileOutput> FileOutputSingleton;