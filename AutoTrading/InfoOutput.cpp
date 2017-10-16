


#include "stdafx.h"
#include "InfoOutput.h"


const char *InfoOutput::m_infoFormat	= "%.4d:[INFO:%s]\t%s\n";
const char *InfoOutput::m_errorFormat	= "%.4d:[ ERR:%s]\t%s\n";
const char *InfoOutput::m_warnFormat	= "%.4d:[WARN:%s]\t%s\n";

InfoOutput::InfoOutput()
{
	t = time(0);   // get time now
	ClearBuffer();
}

InfoOutput::~InfoOutput()
{}

bool InfoOutput::Initialize()
{
	return true;
}


void InfoOutput::Uninitialize()
{

}

void InfoOutput::PrintInfo(const std::string &info)
{
	std::string l_info = info;
	std::lock_guard<std::mutex> autoLock(m_lock);
	ProcessPrintInfo(l_info);
}

void InfoOutput::PrintError(const std::string &error)
{
	std::string l_error = error;
	std::lock_guard<std::mutex> autoLock(m_lock);
	ProcessPrintError(l_error);
}

void InfoOutput::PrintWarning(const std::string &warn)
{
	std::string l_warn = warn;
	std::lock_guard<std::mutex> autoLock(m_lock);
	ProcessPrintWarning(l_warn);
}

void InfoOutput::ProcessPrintInfo(std::string &info)
{
	std::string nowStr;
	Now(nowStr);

	ClearBuffer();
	sprintf_s(m_buffer, m_infoFormat, m_counter++, nowStr.c_str(), info.c_str());
	info = m_buffer;
}

void InfoOutput::ProcessPrintError(std::string &error)
{
	std::string nowStr;
	Now(nowStr);

	ClearBuffer();
	sprintf_s(m_buffer, m_errorFormat, m_counter++, nowStr.c_str(), error.c_str());
	error = m_buffer;
}


void InfoOutput::ProcessPrintWarning(std::string &warn)
{
	std::string nowStr;
	Now(nowStr);

	ClearBuffer();
	sprintf_s(m_buffer, m_warnFormat, m_counter++, nowStr.c_str(), warn.c_str());
	warn = m_buffer;
}

void InfoOutput::ClearBuffer()
{
	memset(m_buffer, 0, sizeof(m_buffer));
}

void InfoOutput::Now(std::string &nowStr)
{
	struct tm now = {0};
	errno_t error = localtime_s(&now, &t);
	if (error == EINVAL)		return;

	ClearBuffer();
	sprintf_s(m_buffer, 
		"%.4d%.2d%.2d-%.2d%.2d%.2d",
		now.tm_year + 1900, 
		now.tm_mon + 1,
		now.tm_mday, 
		now.tm_hour, 
		now.tm_min,
		now.tm_sec);

	nowStr = m_buffer;
}
