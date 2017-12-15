#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_CurrentConfig, when_open_with_registry_currentconfig_then_return_currentconfig)
{
	try
	{
		CRegistryKey regKey{ Registry::CurrentConfig() };
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

TEST_F(Test_RegistryKey_CurrentConfig, when_open_with_registry_currentconfig_then_return_classesroot_should_have_values_and_subkeys)
{
	try
	{
		CRegistryKey regKey{ Registry::CurrentConfig() };
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

TEST_F(Test_RegistryKey_CurrentConfig, when_open_with_registry_currentconfig_then_return_classesroot_should_have_specific_values)
{
	try
	{
		CRegistryKey regKey{ Registry::CurrentConfig() };
		std::vector<BYTE> btVal{ regKey.GetBinaryValue(L"EditFlags") };
		ASSERT_TRUE(btVal.empty());
	}
	catch (exception &ex)
	{
		ASSERT_TRUE(true) << "[EXCEPTION ] " << TUtils::ErrMsg(ex);
	}
	catch (...)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] Unknown exception";
	}
}

TEST_F(Test_RegistryKey_CurrentConfig, when_open_with_registry_currentconfig_then_return_classesroot_should_have_specific_subkeys)
{
	try
	{
		CRegistryKey regKey{ Registry::CurrentConfig() };
		CRegistryKey sub{ regKey.OpenSubKey(L"Software") };
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