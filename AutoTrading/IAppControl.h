#pragma once

#include "InfoOutputUtil.h"


__interface IAppControl
{
	bool Initialize(InfoOutputUtil::EOutputType outputType);
	bool run();
	void Uninitialize();
};