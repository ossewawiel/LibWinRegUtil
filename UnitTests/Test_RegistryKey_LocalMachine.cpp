#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_LocalMachine, when_open_with_registry_localmachine_then_return_localmachine)
{
	try
	{
		CRegistryKey regKey{ Registry::LocalMachine() };
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

TEST_F(Test_RegistryKey_LocalMachine, when_open_with_registry_currentuser_then_return_localmachine_should_have_values_and_subkeys)
{
	try
	{
		CRegistryKey regKey{ Registry::LocalMachine() };
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

TEST_F(Test_RegistryKey_LocalMachine, when_open_with_registry_currentuser_then_return_localmachine_should_have_specific_subkeys)
{
	try
	{
		CRegistryKey regKey{ Registry::LocalMachine() };
		CRegistryKey sub{ regKey.OpenSubKey(L"SOFTWARE") };
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