
#include "stdafx.h"

#include <algorithm>
#include <memory>

#include "InfoOutputUtil.h"
#include "TerminalOutput.h"
#include "FileOutput.h"

#include <cassert>

InfoOutputUtil::InfoOutputUtil()
{}

InfoOutputUtil::~InfoOutputUtil()
{}

bool InfoOutputUtil::Initialize(EOutputType type)
{
	if (type == EOutputType_TERMINAL || type == EOutputType_ALL)
		m_infoOutputList.push_back(new TerminalOutput);
	if (type == EOutputType_FILE || type == EOutputType_ALL)
		m_infoOutputList.push_back(new FileOutput);

	bool res = true;
	std::for_each(m_infoOutputList.begin(), m_infoOutputList.end(), [&res](auto it) {if (res) res = it->Initialize(); });
	return res;
}

void InfoOutputUtil::Uninitialize()
{
	std::for_each(m_infoOutputList.rbegin(), m_infoOutputList.rend(), [](auto p) {
		if (p != NULL)
		{
			p->Uninitialize();
			delete p;
		}
	});
	m_infoOutputList.clear();
}

void InfoOutputUtil::PrintInfo(const std::string &info)
{
	std::for_each(m_infoOutputList.begin(), m_infoOutputList.end(), [&info](auto it) { it->PrintInfo(info); });
}

void InfoOutputUtil::PrintError(const std::string &error)
{
	std::for_each(m_infoOutputList.begin(), m_infoOutputList.end(), [&error](auto it) { it->PrintError(error); });
}

void InfoOutputUtil::PrintWarning(const std::string &warn)
{
	std::for_each(m_infoOutputList.begin(), m_infoOutputList.end(), [&warn](auto it) { it->PrintWarning(warn); });
}


bool InitializeInfoOutputUtilInst(InfoOutputUtil::EOutputType outputType)
{
	std::unique_ptr<InfoOutputUtil> &p = InfoOutputUtilInst::GetSingleton();
	assert(p.get() != nullptr);

	return p->Initialize(outputType);
}

void UninitializeInfoOutputUtilInst()
{
	std::unique_ptr<InfoOutputUtil> &p = InfoOutputUtilInst::GetSingleton();
	assert(p.get() != nullptr);

	p->Uninitialize();
}

void PrintInfo(const std::string &info)
{
	std::unique_ptr<InfoOutputUtil> &p = InfoOutputUtilInst::GetSingleton();
	assert(p.get() != nullptr);

	p->PrintInfo(info);
}

void PrintError(const std::string &error)
{
	std::unique_ptr<InfoOutputUtil> &p = InfoOutputUtilInst::GetSingleton();
	assert(p.get() != nullptr);

	p->PrintError(error);
}

void PrintWarning(const std::string &warn)
{
	std::unique_ptr<InfoOutputUtil> &p = InfoOutputUtilInst::GetSingleton();
	assert(p.get() != nullptr);

	p->PrintWarning(warn);
}