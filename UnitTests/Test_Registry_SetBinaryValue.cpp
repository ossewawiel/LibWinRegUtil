#include "stdafx.h"
#include "Test_Registry.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_Registry_SetSBinaryValue, when_calling_setbinaryvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		Registry::SetBinaryValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_BINARY_VALUENAME, VUC_TESTVAL_1);
		vector<BYTE> vucRegVal{ Registry::GetBinaryValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_BINARY_VALUENAME) };
		for (const auto &val : vucRegVal)
			//{
			//	wcout << L"[  VALUE   ] " << val << endl;
			//}
			ASSERT_EQ(vucRegVal, VUC_TESTVAL_1) << "[  FAILED  ] vucRegVal is not equal to VUC_TESTVAL_1";

		Registry::SetBinaryValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_BINARY_VALUENAME, VUC_TESTVAL_2);
		vucRegVal = Registry::GetBinaryValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_BINARY_VALUENAME);
		//for (const auto &val : vucRegVal)
		//{
		//	wcout << L"[  VALUE   ] " << val << endl;
		//}
		ASSERT_EQ(vucRegVal, VUC_TESTVAL_2) << "[  FAILED  ] vwsRegVal is not equal to VUC_TESTVAL_1";
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

TEST_F(Test_Registry_SetSBinaryValue, when_calling_setbinaryvalue_with_invalid_hkey_expect_exception)
{
	try
	{
		Registry::SetBinaryValue(eHKey::eHkeyNotDefined, WS_TEST_SUBKEY, WS_BINARY_VALUENAME, VUC_TESTVAL_1);
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