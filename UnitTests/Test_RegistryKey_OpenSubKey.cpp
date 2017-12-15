#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_OpenSubKey, when_open_with_registry_with_subkey_then_return_subkey)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
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

TEST_F(Test_RegistryKey_OpenSubKey, when_open_with_registry_with_subkey_then_return_correct_key_name)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		std::wstring wsKeyName{ regKey.Name() };
		ASSERT_EQ(wsKeyName, WS_TEST_KEY_NAME) << "[  FAILED  ] wsKeyName is not equal to WS_TEST_KEY_NAME";
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

TEST_F(Test_RegistryKey_OpenSubKey, when_open_with_registry_with_subkey_then_return_correct_amount_of_values)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		int iValueNames{ regKey.ValueCount() };
		ASSERT_EQ(iValueNames, 6) << "[  FAILED  ] iValueNames is not equal to 6";
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

TEST_F(Test_RegistryKey_OpenSubKey, when_open_with_registry_with_subkey_then_return_correct_amount_of_keys)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		int iKeys{ regKey.SubKeyCount() };
		ASSERT_EQ(iKeys, 2) << "[  FAILED  ] iKeys is not equal to 2";
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