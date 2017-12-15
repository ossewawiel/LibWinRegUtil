#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_DeleteValue, when_calling_deletevalue_then_enusre_value_is_gone)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY, eRegAccessRights::eAccessKeyAllAccess) };
		//confirm testvalue do not exist
		std::vector<std::wstring> vwsValueNames{ regKey.GetValueNames() };
		int items{ std::count(vwsValueNames.cbegin(), vwsValueNames.cend(), WS_STRING_NEWVALUENAME) };
		ASSERT_TRUE(items == 0);

		//create new value and confirm existence
		regKey.SetStringValue(WS_STRING_NEWVALUENAME, WS_TESTNEWVAL);
		vwsValueNames = regKey.GetValueNames();
		items = std::count(vwsValueNames.cbegin(), vwsValueNames.cend(), WS_STRING_NEWVALUENAME);
		ASSERT_TRUE(items == 1);

		//delete value and confirm it is gone
		regKey.DeleteValue(WS_STRING_NEWVALUENAME);
		vwsValueNames = regKey.GetValueNames();
		items = std::count(vwsValueNames.cbegin(), vwsValueNames.cend(), WS_STRING_NEWVALUENAME);
		ASSERT_TRUE(items == 0);
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