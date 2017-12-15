#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_GetValue, when_calling_getstringvalue_with_valid_parameter_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		std::wstring wsRegVal{ regKey.GetStringValue(WS_STRING_VALUENAME) };
		ASSERT_FALSE(wsRegVal.empty()) << "[  FAILED  ] wsRegVal is empty";
		ASSERT_FALSE(wsRegVal == WS_DEFAULT) << "[  FAILED  ] wsRegVal is default value";
		wcout << L"[  VALUE   ] " << wsRegVal.c_str() << endl;
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

TEST_F(Test_RegistryKey_GetValue, when_calling_getmultistringvalue_with_valid_parameter_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		std::vector<std::wstring> vwsRegVal{ regKey.GetMultiStringValue(WS_MULTISTRING_VALUENAME) };
		ASSERT_FALSE(vwsRegVal.empty()) << "[  FAILED  ] vwsRegVal is empty";
		for (const auto &val : vwsRegVal)
		{
			ASSERT_TRUE(val.length() > 0) << "[  FAILED  ] val is empty";
		}
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

TEST_F(Test_RegistryKey_GetValue, when_calling_getexpandedstringvalue_with_valid_parameter_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		wstring wsRegVal{ regKey.GetExpandedStringValue(WS_EXPANDEDSTRING_VALUENAME) };
		ASSERT_FALSE(wsRegVal.empty()) << "[  FAILED  ] wsRegVal is empty";
		ASSERT_FALSE(wsRegVal == WS_DEFAULT) << "[  FAILED  ] wsRegVal is default value";
		//wcout << L"[  VALUE   ] " << wsRegVal.c_str() << endl;
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

TEST_F(Test_RegistryKey_GetValue, when_calling_getdwordvalue_with_valid_parameter_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		DWORD dwRegVal{ regKey.GetDwordValue(WS_DWORD_VALUENAME) };
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

TEST_F(Test_RegistryKey_GetValue, when_calling_getqwordvalue_with_valid_parameter_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		ULONGLONG qwRegVal{ regKey.GetQwordValue(WS_QWORD_VALUENAME) };
		ASSERT_FALSE(qwRegVal == 0) << "[  FAILED  ] dwRegVal is 0";
		ASSERT_FALSE(qwRegVal == DW_DEFAULT) << "[  FAILED  ] dwRegVal is default value";
		//wcout << L"[  VALUE   ] " << qwRegVal << endl;
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

TEST_F(Test_RegistryKey_GetValue, when_calling_getbinaryvalue_with_valid_parameter_values_expect_no_exception)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		vector<unsigned char> vucRegVal{ regKey.GetBinaryValue(WS_BINARY_VALUENAME) };
		ASSERT_FALSE(vucRegVal.empty()) << "[  FAILED  ] vwsRegVal is empty";
		for (const auto &val : vucRegVal)
		{
			ASSERT_TRUE(val > 0) << L"[  VALUE   ] " << val << endl;
		}
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