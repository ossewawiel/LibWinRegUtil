#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_GetValueKind, when_calling_getvaluekind_then_return_correct_valuekind)
{
	try
	{
		CRegistryKey regKey{ Registry::Users().OpenSubKey(WS_TEST_SUBKEY) };
		std::vector<std::wstring> vwsValueNames{ regKey.GetValueNames() };
		ASSERT_TRUE(vwsValueNames.size() > 0) << "[  FAILED  ] vwsValueNames.size() is not equal to 6";
		for (auto item : vwsValueNames)
		{
			ASSERT_TRUE(item.length() > 0) << "[  FAILED  ] item.length() is not greater than 0";
			eRegValueKind valueKind{ regKey.GetValueKind(item) };
			ASSERT_TRUE(valueKind != eRegValueKind::eValueKindUnknown) << "[  FAILED  ] " << item << " valueKind is eValueKindUnknown";
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