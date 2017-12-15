#include "stdafx.h"
#include "Test_Registry.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_Registry_SetSDwordValue, when_calling_setdwordgvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		Registry::SetDwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_DWORD_VALUENAME, DW_TESTVAL_1);
		DWORD dwRegVal{ Registry::GetDwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_DWORD_VALUENAME) };
		//wcout << L"[  VALUE   ] " << dwRegVal << endl;
		ASSERT_EQ(dwRegVal, DW_TESTVAL_1) << "[  FAILED  ] dwRegVal is not equal to DW_TESTVAL_1";

		Registry::SetDwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_DWORD_VALUENAME, DW_TESTVAL_2);
		dwRegVal = Registry::GetDwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_DWORD_VALUENAME);
		//wcout << L"[  VALUE   ] " << dwRegVal << endl;
		ASSERT_EQ(dwRegVal, DW_TESTVAL_2) << "[  FAILED  ] dwRegVal is not equal to DW_TESTVAL_2";
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

TEST_F(Test_Registry_SetSDwordValue, when_calling_setdwordgvalue_with_invalid_hkey_expect_exception)
{
	try
	{
		Registry::SetDwordValue(eHKey::eHkeyNotDefined, WS_TEST_SUBKEY, WS_DWORD_VALUENAME, DW_TESTVAL_1);
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