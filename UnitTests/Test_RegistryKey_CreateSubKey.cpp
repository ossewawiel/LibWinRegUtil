#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_CreateSubKey, when_createsubkey_with_new_key_and_valid_parameters_then_return_new_subkey_and_confirm_its_existence)
{
	try
	{
		//Check if subkey do not already exist
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		std::vector<std::wstring> subKeyNames{regKey.GetSubKeyNames()};
		int items{ std::count(subKeyNames.cbegin(), subKeyNames.cend(), WS_NEW_SUBKEY) };
		ASSERT_TRUE(items == 0);

		//create subkey and ensure it is there
		CRegistryKey subKey{ regKey.CreateSubKey(WS_NEW_SUBKEY)};
		std::wstring wsNewSubKeyName{ subKey.Name() };
		ASSERT_EQ(wsNewSubKeyName, WS_NEW_SUBKEY_NAME) << "[  FAILED  ] wsNewSubKeyName is not WS_NEW_SUBKEY_NAME";
		subKeyNames = regKey.GetSubKeyNames();
		items = std::count(subKeyNames.cbegin(), subKeyNames.cend(), WS_NEW_SUBKEY);
		ASSERT_TRUE(items >= 1);

		//Delete subkey and ensure it is gone
		regKey.DeleteSubKey(WS_NEW_SUBKEY);
		subKeyNames = regKey.GetSubKeyNames();
		items = std::count(subKeyNames.cbegin(), subKeyNames.cend(), WS_NEW_SUBKEY);
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

