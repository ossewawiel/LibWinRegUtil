#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_ClassesRoot, when_open_with_registry_classesroot_then_return_classesroot)
{
	try
	{
		CRegistryKey regKey{ Registry::ClassesRoot() };
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

TEST_F(Test_RegistryKey_ClassesRoot, when_open_with_registry_classesroot_then_return_classesroot_should_have_values_and_subkeys)
{
	try
	{
		CRegistryKey regKey{ Registry::ClassesRoot() };
		ASSERT_TRUE(regKey.ValueCount() == 1);
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

TEST_F(Test_RegistryKey_ClassesRoot, when_open_with_registry_classesroot_then_return_classesroot_should_have_specific_values)
{
	try
	{
		CRegistryKey regKey{ Registry::ClassesRoot() };
		std::vector<BYTE> btVal{ regKey.GetBinaryValue(L"EditFlags") };
		ASSERT_FALSE(btVal.empty());
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

TEST_F(Test_RegistryKey_ClassesRoot, when_open_with_registry_classesroot_then_return_classesroot_should_have_specific_subkeys)
{
	try
	{
		CRegistryKey regKey{ Registry::ClassesRoot() };
		CRegistryKey sub{ regKey.OpenSubKey(L"*") };
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