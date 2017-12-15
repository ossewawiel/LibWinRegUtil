#include "stdafx.h"
#include "Test_Registry.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_Registry_SetSQwordValue, when_calling_setqwordgvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		Registry::SetQwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_QWORD_VALUENAME, QW_TESTVAL_1);
		ULONGLONG qwRegVal{ Registry::GetQwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_QWORD_VALUENAME) };
		//wcout << L"[  VALUE   ] " << dwRegVal << endl;
		ASSERT_EQ(qwRegVal, QW_TESTVAL_1) << "[  FAILED  ] qwRegVal is not equal to QW_TESTVAL_1";

		Registry::SetQwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_QWORD_VALUENAME, QW_TESTVAL_2);
		qwRegVal = Registry::GetQwordValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_QWORD_VALUENAME);
		//wcout << L"[  VALUE   ] " << dwRegVal << endl;
		ASSERT_EQ(qwRegVal, QW_TESTVAL_2) << "[  FAILED  ] qwRegVal is not equal to QW_TESTVAL_2";
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

TEST_F(Test_Registry_SetSQwordValue, when_calling_setqwordgvalue_with_invalid_hkey_expect_exception)
{
	try
	{
		Registry::SetQwordValue(eHKey::eHkeyNotDefined, WS_TEST_SUBKEY, WS_QWORD_VALUENAME, QW_TESTVAL_1);
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
