#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_GetSubKeyNames, when_calling_getsubkeynames_then_return_correct_valuenames)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		std::vector<std::wstring> vwsSubKeyNames{ regKey.GetSubKeyNames() };
		ASSERT_TRUE(vwsSubKeyNames.size() == 2) << "[  FAILED  ] vwsSubKeyNames.size() is not equal to 2";
		for (auto item : vwsSubKeyNames)
		{
			ASSERT_TRUE(item.length() > 0) << "[  FAILED  ] item.length() is not greater than 0";
		}
	}
	catch (exception &ex)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] " << TUtils::ErrMsg(ex);
	}
	catch (...)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] Unknown exception";
	}
}