#pragma once
#include "stdafx.h"

namespace TConst
{
	
	const std::wstring WS_INVALID_PARAM_VALUE{ L"Invalid parameter value." };
	const std::wstring WS_CANNOT_FIND_FILE{ L"The system cannot find the file specified" };
	
	const std::wstring WS_TEST_SUBKEY{ L".DEFAULT\\Software\\LibWinRegUtilTest" };
	
	const std::wstring WS_NEW_SUBKEY{ L"NewSubKey" };
	const std::wstring WS_CLASSES_ROOT{ L"HKEY_CLASSES_ROOT" };
	const std::wstring WS_USERS(L"HKEY_USERS");
	const std::wstring WS_TEST_KEY_NAME{ WS_USERS + L"\\" + WS_TEST_SUBKEY };
	const std::wstring WS_NEW_SUBKEY_NAME{ WS_USERS + L"\\" + WS_TEST_SUBKEY + L"\\" + WS_NEW_SUBKEY };
	const std::wstring WS_INVALID_SUBKEY{ L"x" };
	const std::wstring WS_INVALID_VALNAME{ L"x" };
	
	const std::wstring WS_DEFAULT{ L"DefaultVal" };
	const std::wstring WS_TESTVAL_1{ L"TestValue1" };
	const std::wstring WS_TESTVAL_2{ L"TestValue2" };
	const std::wstring WS_STRING_VALUENAME{ L"TestStringValue" };

	const std::wstring WS_STRING_NEWVALUENAME{ L"TestStringNewValue" };
	const std::wstring WS_TESTNEWVAL{ L"TestNewValue" };

	const std::wstring WS_ES_TESTVAL_1{ L"%SystemRoot%\\LibWinRegUtilTest" };
	const std::wstring WS_ES_TESTVAL_2{ L"%SystemRoot%\\LibWinRegUtilTest_2" };
	const std::wstring WS_EXPANDEDSTRING_VALUENAME{ L"TestExpandedStringValue" };
	
	const DWORD DW_DEFAULT{ 1 };
	const DWORD DW_TESTVAL_1{ 123456789 };
	const DWORD DW_TESTVAL_2{ 987654321 };
	const std::wstring WS_DWORD_VALUENAME{ L"TestDwordValue" };

	const ULONGLONG QW_DEFAULT{ 1 };
	const ULONGLONG QW_TESTVAL_1{ 12345678987654321 };
	const ULONGLONG QW_TESTVAL_2{ 98765432123456789 };
	const std::wstring WS_QWORD_VALUENAME{ L"TestQwordValue" };
	
	const std::vector<std::wstring> VWS_TESTVAL_1{ L"TestA1", L"TestA2", L"TestA3" };
	const std::vector<std::wstring> VWS_TESTVAL_2{ L"TestB1", L"TestB2", L"TestB3" };
	const std::wstring WS_MULTISTRING_VALUENAME{ L"TestMultiStringValue" };
	
	const std::vector<BYTE> VUC_TESTVAL_1{ 1, 2, 3, 4, 5, 6, 7 };
	const std::vector<BYTE> VUC_TESTVAL_2{ 7, 6, 5, 4, 3, 2, 1 };
	const std::wstring WS_BINARY_VALUENAME{ L"TestBinaryValue" };
}
