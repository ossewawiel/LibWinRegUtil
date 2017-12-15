#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;



TEST_F(Test_RegistryKey_SubKeyCount, when_get_subkeycount_then_return_count_greater_than_1)
{
	try
	{
		CRegistryKey regKey{ Registry::ClassesRoot() };
		int iSubKeyCount{ regKey.SubKeyCount() };
		ASSERT_TRUE(iSubKeyCount > 1) << "[  FAILED  ] iSubKeyCount is " << iSubKeyCount;
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