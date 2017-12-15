// UnitTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

