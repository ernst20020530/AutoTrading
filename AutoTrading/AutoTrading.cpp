// AutoTrading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <algorithm>

#include "AutoTradingApp.h"
#include "InfoOutputUtil.h"

using namespace std;

#ifdef  assert
#undef assert
#include <cassert>
#endif //  assert

int main(int argc, char** argv)
{
	InfoOutputUtil::EOutputType outputType = InfoOutputUtil::EOutputType_UNKNOWN;
	bool validArgument = true;
	switch (argc)
	{
	case 1:
		outputType = InfoOutputUtil::EOutputType_ALL;
		break;
	case 2:
	{
		if (argv[0] == nullptr)
		{
			validArgument = false;
			break;
		}
		string arg1(argv[0]);
		if(arg1.compare("terminal"))
			outputType = InfoOutputUtil::EOutputType_TERMINAL;
		else if (arg1.compare("file"))
			outputType = InfoOutputUtil::EOutputType_FILE;
		else if (arg1.compare("all"))
			outputType = InfoOutputUtil::EOutputType_ALL;
		break;
	}
	}

	if (!validArgument)
	{
		return -1;
	}

	unique_ptr<AutoTradingAppSingleton::Type> &autoTrading = AutoTradingAppSingleton::GetSingleton();
	assert(autoTrading.get() != nullptr);

	AutoTradingAppSingleton::Type::Scope appScope(autoTrading.get());

	appScope->Initialize(outputType);
	appScope->run();

	UninitializeInfoOutputUtilInst();

    return 0;
}

