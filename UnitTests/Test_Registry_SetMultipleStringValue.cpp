#include "stdafx.h"
#include "Test_Registry.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_Registry_SetMultipleStringValue, when_calling_setmultistringvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		Registry::SetMultiStringValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_MULTISTRING_VALUENAME, VWS_TESTVAL_1);
		vector<wstring> vwsRegVal{ Registry::GetMultiStringValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_MULTISTRING_VALUENAME) };
		//for (const auto &val : vwsRegVal)
		//{
		//	wcout << L"[  VALUE   ] " << val << endl;
		//}
		ASSERT_EQ(vwsRegVal, VWS_TESTVAL_1) << "[  FAILED  ] vwsRegVal is not equal to VWS_TESTVAL_1";

		Registry::SetMultiStringValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_MULTISTRING_VALUENAME, VWS_TESTVAL_2);
		vwsRegVal = Registry::GetMultiStringValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_MULTISTRING_VALUENAME);
		//for (const auto &val : vwsRegVal)
		//{
		//	wcout << L"[  VALUE   ] " << val << endl;
		//}
		ASSERT_EQ(vwsRegVal, VWS_TESTVAL_2) << "[  FAILED  ] vwsRegVal is not equal to VWS_TESTVAL_2";
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

TEST_F(Test_Registry_SetMultipleStringValue, when_calling_setmultiplestringvalue_with_invalid_hkey_expect_exception)
{
	try
	{
		Registry::SetMultiStringValue(eHKey::eHkeyNotDefined, WS_TEST_SUBKEY, WS_MULTISTRING_VALUENAME, VWS_TESTVAL_1);
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