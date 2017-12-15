#include "stdafx.h"
#include "Test_RegistryKey.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_RegistryKey_View, when_get_view_then_return_default_when_none_specified)
{
	try
	{
		CRegistryKey regKey{ Registry::ClassesRoot() };
		eRegView regView{ regKey.View() };
		ASSERT_EQ(regView, eRegView::eViewDefault) << "[  FAILED  ] regView is " << static_cast<int>(regView);
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