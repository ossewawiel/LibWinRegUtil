#include "stdafx.h"
#include "Test_Registry.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_Registry_GetDwordValue, when_calling_getdwordvalue_with_valid_parameter_values_expect_no_exception)
{
	try
	{
		DWORD dwRegVal{ Registry::GetDwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_DWORD_VALUENAME) };
		ASSERT_FALSE(dwRegVal == 0) << "[  FAILED  ] dwRegVal is 0";
		ASSERT_FALSE(dwRegVal == DW_DEFAULT) << "[  FAILED  ] dwRegVal is default value";
		wcout << L"[  VALUE   ] " << dwRegVal << endl;
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

TEST_F(Test_Registry_GetDwordValue, when_calling_getdwordvalue_with_invalid_hkey_type_expect_exception)
{
	try
	{
		DWORD dwRegVal{ Registry::GetDwordValue(eHKey::eHkeyNotDefined, WS_TEST_SUBKEY, WS_DWORD_VALUENAME) };
		ASSERT_FALSE(true) << "[  FAILED  ] Expected an exception";
	}
	catch (exception &ex)
	{
		ASSERT_TRUE(TUtils::InString(TUtils::ErrMsg(ex), WS_INVALID_PARAM_VALUE)) << "[EXCEPTION ] " << TUtils::ErrMsg(ex);
	}
	catch (...)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] Unknown exception";
	}
}

TEST_F(Test_Registry_GetDwordValue, when_calling_getdwordvalue_with_no_valuename_expect_exception)
{
	try
	{
		DWORD dwRegVal{ Registry::GetDwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, L"") };
		ASSERT_FALSE(true) << "[  FAILED  ] Expected an exception";
	}
	catch (exception &ex)
	{
		ASSERT_TRUE(TUtils::InString(TUtils::ErrMsg(ex), WS_CANNOT_FIND_FILE)) << "[EXCEPTION ] " << TUtils::ErrMsg(ex);
	}
	catch (...)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] Unknown exception";
	}
}


TEST_F(Test_Registry_GetDwordValue, when_calling_getdwordvalue_with_invalid_valuename_expect_exception)
{
	try
	{
		DWORD dwRegVal{ Registry::GetDwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_INVALID_VALNAME) };
		ASSERT_FALSE(true) << "[  FAILED  ] Expected an exception";
	}
	catch (exception &ex)
	{
		ASSERT_TRUE(TUtils::InString(TUtils::ErrMsg(ex), WS_CANNOT_FIND_FILE)) << "[EXCEPTION ] " << TUtils::ErrMsg(ex);
	}
	catch (...)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] Unknown exception";
	}
}

TEST_F(Test_Registry_GetDwordValue, when_calling_getdwordvalue_with_invalid_subkey_expect_exception)
{
	try
	{
		DWORD dwRegVal{ Registry::GetDwordValue(eHKey::eHKeyUsers, WS_INVALID_SUBKEY, WS_DWORD_VALUENAME) };
		ASSERT_FALSE(true) << "[  FAILED  ] Expected an exception";
	}
	catch (exception &ex)
	{
		ASSERT_TRUE(TUtils::InString(TUtils::ErrMsg(ex), WS_CANNOT_FIND_FILE)) << "[EXCEPTION ] " << TUtils::ErrMsg(ex);
	}
	catch (...)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] Unknown exception";
	}
}

TEST_F(Test_Registry_GetDwordValue, when_calling_getdwordvalue_with_invalid_subkey_and_returndefault_set_expect_no_exception_and_default_value)
{
	try
	{
		DWORD dwRegVal{ Registry::GetDwordValue(eHKey::eHKeyUsers, WS_INVALID_SUBKEY, WS_DWORD_VALUENAME, true, DW_DEFAULT) };
		ASSERT_EQ(dwRegVal, DW_DEFAULT) << "[  FAILED  ] dwRegVal is not default";
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

TEST_F(Test_Registry_GetDwordValue, when_calling_getdwordvalue_with_invalid_valuename_and_returndefault_set_expect_no_exception_and_default_value)
{
	try
	{
		DWORD dwRegVal{ Registry::GetDwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_INVALID_VALNAME, true, DW_DEFAULT) };
		ASSERT_EQ(dwRegVal, DW_DEFAULT) << "[  FAILED  ] wsRegVal is not empty";
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