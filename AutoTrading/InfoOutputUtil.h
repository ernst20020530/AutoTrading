#pragma once

#include <list>

#include "InfoOutput.h"
#include "Singleton.h"

/**
@brief		list of information output. This is singleton.
*/

class InfoOutputUtil
{
public:

	enum EOutputType
	{
		EOutputType_UNKNOWN,
		EOutputType_TERMINAL,
		EOutputType_FILE,
		EOutputType_ALL,
		EOutputType_MAX
	};

	virtual ~InfoOutputUtil();

	bool Initialize(EOutputType type);
	void Uninitialize();
	void PrintInfo(const std::string &info);
	void PrintError(const std::string &error);
	void PrintWarning(const std::string &warn);

private:

	friend Singleton<InfoOutputUtil>;

	InfoOutputUtil();

	std::list<InfoOutput*>	m_infoOutputList;
};

typedef Singleton<InfoOutputUtil> InfoOutputUtilInst;

bool InitializeInfoOutputUtilInst(InfoOutputUtil::EOutputType outputType);
void UninitializeInfoOutputUtilInst();

void PrintInfo(const std::string &info);
void PrintError(const std::string &error);
void PrintWarning(const std::string &warn);