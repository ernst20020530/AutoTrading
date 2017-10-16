

#include "stdafx.h"

#include "FileOutput.h"

FileOutput::FileOutput()
{
	std::string nowStr;
	Now(nowStr);

	std::string fileName("audit");
	fileName += nowStr + ".log";

	m_file.open(fileName, std::ios::out);
}

FileOutput::~FileOutput()
{
	m_file.close();
}

void FileOutput::ProcessPrintInfo(std::string &info)
{
	if (!m_file.is_open())	return;

	InfoOutput::ProcessPrintInfo(info);

	m_file << info;
	m_file.flush();
}

void FileOutput::ProcessPrintError(std::string &error)
{
	if (!m_file.is_open())	return;

	InfoOutput::ProcessPrintError(error);

	m_file << error;
	m_file.flush();
}

void FileOutput::ProcessPrintWarning(std::string &warn)
{
	if (!m_file.is_open())	return;

	InfoOutput::ProcessPrintWarning(warn);

	m_file << warn;
	m_file.flush();
}