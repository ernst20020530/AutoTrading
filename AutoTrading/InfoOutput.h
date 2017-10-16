#pragma once

#include <string>
#include <ctime>
#include <mutex>

class InfoOutput abstract
{
public:
	InfoOutput(InfoOutput &&o) = delete;
	InfoOutput(const InfoOutput &o) = delete;
	virtual ~InfoOutput();

	virtual bool Initialize();
	virtual void Uninitialize();

	void PrintInfo(const std::string &info);
	void PrintError(const std::string &error);
	void PrintWarning(const std::string &warn);

protected:
	InfoOutput();
	virtual void ProcessPrintInfo(std::string &info);
	virtual void ProcessPrintError(std::string &error);
	virtual void ProcessPrintWarning(std::string &warn);
	void Now(std::string &nowStr);

private:

	void ClearBuffer();

	static const char *m_infoFormat;
	static const char *m_errorFormat;
	static const char *m_warnFormat;

	unsigned int m_counter = 1;
	char	m_buffer[1024];

	bool	m_enabled = true;

	time_t t;
	std::mutex	m_lock;
};