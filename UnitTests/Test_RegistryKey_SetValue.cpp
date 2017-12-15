#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_SetValue, when_calling_setstringvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY, eRegAccessRights::eAccessKeyAllAccess) };
		regKey.SetStringValue(WS_STRING_VALUENAME, WS_TESTVAL_1);
		wstring wsRegVal{ regKey.GetStringValue(WS_STRING_VALUENAME) };
		//wcout << L"[  VALUE   ] " << wsRegVal.c_str() << endl;
		ASSERT_EQ(wsRegVal, WS_TESTVAL_1) << "[  FAILED  ] wsRegVal is not equal to WS_TESTVAL_1";

		regKey.SetStringValue(WS_STRING_VALUENAME, WS_TESTVAL_2);
		wsRegVal = regKey.GetStringValue(WS_STRING_VALUENAME);
		//wcout << L"[  VALUE   ] " << wsRegVal.c_str() << endl;
		ASSERT_EQ(wsRegVal, WS_TESTVAL_2) << "[  FAILED  ] wsRegVal is not equal to WS_TESTVAL_2";
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

TEST_F(Test_RegistryKey_SetValue, when_calling_setmultistringvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY, eRegAccessRights::eAccessKeyAllAccess) };
		regKey.SetMultiStringValue(WS_MULTISTRING_VALUENAME, VWS_TESTVAL_1);
		vector<wstring> vwsRegVal{ regKey.GetMultiStringValue(WS_MULTISTRING_VALUENAME) };
		ASSERT_EQ(vwsRegVal, VWS_TESTVAL_1) << "[  FAILED  ] vwsRegVal is not equal to VWS_TESTVAL_1";

		regKey.SetMultiStringValue(WS_MULTISTRING_VALUENAME, VWS_TESTVAL_2);
		vwsRegVal = regKey.GetMultiStringValue(WS_MULTISTRING_VALUENAME);
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

TEST_F(Test_RegistryKey_SetValue, when_calling_setexpandedstringvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY, eRegAccessRights::eAccessKeyAllAccess) };
		regKey.SetExpandedStringValue(WS_EXPANDEDSTRING_VALUENAME, WS_ES_TESTVAL_1);
		wstring wsRegVal{ regKey.GetExpandedStringValue(WS_EXPANDEDSTRING_VALUENAME) };
		//wcout << L"[  VALUE   ] " << wsRegVal.c_str() << endl;
		ASSERT_EQ(wsRegVal, WS_ES_TESTVAL_1) << "[  FAILED  ] wsRegVal is not equal to WS_ES_TESTVAL_1";

		regKey.SetExpandedStringValue(WS_EXPANDEDSTRING_VALUENAME, WS_ES_TESTVAL_2);
		wsRegVal = regKey.GetExpandedStringValue(WS_EXPANDEDSTRING_VALUENAME);
		//wcout << L"[  VALUE   ] " << wsRegVal.c_str() << endl;
		ASSERT_EQ(wsRegVal, WS_ES_TESTVAL_2) << "[  FAILED  ] wsRegVal is not equal to WS_ES_TESTVAL_2";
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

TEST_F(Test_RegistryKey_SetValue, when_calling_setbinaryvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY, eRegAccessRights::eAccessKeyAllAccess) };
		regKey.SetBinaryValue(WS_BINARY_VALUENAME, VUC_TESTVAL_1);
		vector<BYTE> vucRegVal{ regKey.GetBinaryValue(WS_BINARY_VALUENAME) };
		for (const auto &val : vucRegVal)
			//{
			//	wcout << L"[  VALUE   ] " << val << endl;
			//}
			ASSERT_EQ(vucRegVal, VUC_TESTVAL_1) << "[  FAILED  ] vucRegVal is not equal to VUC_TESTVAL_1";

		regKey.SetBinaryValue(WS_BINARY_VALUENAME, VUC_TESTVAL_2);
		vucRegVal = regKey.GetBinaryValue(WS_BINARY_VALUENAME);
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

TEST_F(Test_RegistryKey_SetValue, when_calling_setdwordgvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY, eRegAccessRights::eAccessKeyAllAccess) };
		regKey.SetDwordValue(WS_DWORD_VALUENAME, DW_TESTVAL_1);
		DWORD dwRegVal{ regKey.GetDwordValue(WS_DWORD_VALUENAME) };
		//wcout << L"[  VALUE   ] " << dwRegVal << endl;
		ASSERT_EQ(dwRegVal, DW_TESTVAL_1) << "[  FAILED  ] dwRegVal is not equal to DW_TESTVAL_1";

		regKey.SetDwordValue(WS_DWORD_VALUENAME, DW_TESTVAL_2);
		dwRegVal = regKey.GetDwordValue(WS_DWORD_VALUENAME);
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

TEST_F(Test_RegistryKey_SetValue, when_calling_setqwordgvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY, eRegAccessRights::eAccessKeyAllAccess) };
		regKey.SetQwordValue(WS_QWORD_VALUENAME, QW_TESTVAL_1);
		ULONGLONG qwRegVal{ regKey.GetQwordValue(WS_QWORD_VALUENAME) };
		//wcout << L"[  VALUE   ] " << dwRegVal << endl;
		ASSERT_EQ(qwRegVal, QW_TESTVAL_1) << "[  FAILED  ] qwRegVal is not equal to QW_TESTVAL_1";

		regKey.SetQwordValue(WS_QWORD_VALUENAME, QW_TESTVAL_2);
		qwRegVal = regKey.GetQwordValue(WS_QWORD_VALUENAME);
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