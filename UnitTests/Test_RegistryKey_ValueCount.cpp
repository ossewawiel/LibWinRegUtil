#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_ValueCount, when_get_valuecount_then_return_count_greater_than_1)
{
	try
	{
		CRegistryKey regKey{ Registry::ClassesRoot() };
		int iValueCount{ regKey.ValueCount() };
		ASSERT_TRUE(iValueCount > 0) << "[  FAILED  ] iValueCount is " << iValueCount;
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