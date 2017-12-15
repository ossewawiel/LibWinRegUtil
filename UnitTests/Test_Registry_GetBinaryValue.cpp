#include "stdafx.h"
#include "Test_Registry.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_Registry_GetBinaryValue, when_calling_getbinaryvalue_with_valid_parameter_values_expect_no_exception)
{
	try
	{
		vector<unsigned char> vucRegVal{ Registry::GetBinaryValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_BINARY_VALUENAME) };
		ASSERT_FALSE(vucRegVal.empty()) << "[  FAILED  ] vwsRegVal is empty";
		//for (const auto &val : vucRegVal)
		//{
		//	wcout << L"[  VALUE   ] " << val << endl;
		//}
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

TEST_F(Test_Registry_GetBinaryValue, when_calling_getbinaryvalue_with_invalid_hkey_type_expect_exception)
{
	try
	{
		vector<BYTE> vucRegVal{ Registry::GetBinaryValue(eHKey::eHkeyNotDefined, WS_TEST_SUBKEY, WS_BINARY_VALUENAME) };
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

TEST_F(Test_Registry_GetBinaryValue, when_calling_getbinaryvalue_with_no_valuename_expect_exception)
{
	try
	{
		vector<BYTE> vucRegVal{ Registry::GetBinaryValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, L"") };
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

TEST_F(Test_Registry_GetBinaryValue, when_calling_getbinaryvalue_with_invalid_valuename_expect_exception)
{
	try
	{
		vector<BYTE> vucRegVal{ Registry::GetBinaryValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_INVALID_VALNAME) };
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

TEST_F(Test_Registry_GetBinaryValue, when_calling_getbinaryvalue_with_invalid_subkey_expect_exception)
{
	try
	{
		vector<BYTE> vucRegVal{ Registry::GetBinaryValue(eHKey::eHKeyUsers, WS_INVALID_SUBKEY, WS_BINARY_VALUENAME) };
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

TEST_F(Test_Registry_GetBinaryValue, when_calling_getbinaryvalue_with_invalid_subkey_and_returndefault_set_expect_no_exception_and_empty_vector)
{
	try
	{
		vector<BYTE> vucRegVal{ Registry::GetBinaryValue(eHKey::eHKeyUsers, WS_INVALID_SUBKEY, WS_BINARY_VALUENAME, true) };
		ASSERT_EQ(vucRegVal.size(), 0) << "[  FAILED  ] vwsRegVal.size() is not 0";
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

TEST_F(Test_Registry_GetBinaryValue, when_calling_getbinaryvalue_with_invalid_valuename_and_returndefault_set_expect_no_exception_and_empty_vector)
{
	try
	{
		vector<BYTE> vucRegVal{ Registry::GetBinaryValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_INVALID_VALNAME, true) };
		ASSERT_EQ(vucRegVal.size(), 0) << "[  FAILED  ] vwsRegVal.size() is not 0";
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