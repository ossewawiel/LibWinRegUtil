#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_Name, when_get_name_then_return_name_of_key)
{
	try
	{
		CRegistryKey regKey{ Registry::ClassesRoot() };
		std::wstring wsKeyName{ regKey.Name() };
		ASSERT_EQ(wsKeyName, WS_CLASSES_ROOT);
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