#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_Users, when_open_with_registry_users_then_return_users)
{
	try
	{
		CRegistryKey regKey{ Registry::Users() };
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

TEST_F(Test_RegistryKey_Users, when_open_with_registry_users_then_return_classesroot_should_have_values_and_subkeys)
{
	try
	{
		CRegistryKey regKey{ Registry::Users() };
		ASSERT_TRUE(regKey.ValueCount() == 0);
		ASSERT_TRUE(regKey.SubKeyCount() > 1);
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

TEST_F(Test_RegistryKey_Users, when_open_with_registry_users_then_return_classesroot_should_have_specific_subkeys)
{
	try
	{
		CRegistryKey regKey{ Registry::Users() };
		CRegistryKey sub{ regKey.OpenSubKey(L".DEFAULT") };
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