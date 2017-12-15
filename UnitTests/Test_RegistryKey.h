#pragma once

using namespace WinReg;

class Test_RegistryKey :
	public ::testing::Test
{
public:
	virtual void SetUp() { }
	virtual void TearDown() { }
};

class Test_RegistryKey_ClassesRoot : public Test_RegistryKey {};
class Test_RegistryKey_CurrentConfig : public Test_RegistryKey {};
class Test_RegistryKey_CurrentUser : public Test_RegistryKey {};
class Test_RegistryKey_LocalMachine : public Test_RegistryKey {};
class Test_RegistryKey_Users : public Test_RegistryKey {};
class Test_RegistryKey_OpenSubKey : public Test_RegistryKey {};
class Test_RegistryKey_Name : public Test_RegistryKey {};
class Test_RegistryKey_SubKeyCount : public Test_RegistryKey {};
class Test_RegistryKey_ValueCount : public Test_RegistryKey {};
class Test_RegistryKey_View : public Test_RegistryKey {};
class Test_RegistryKey_GetValueNames : public Test_RegistryKey {};
class Test_RegistryKey_GetValueKind : public Test_RegistryKey {};
class Test_RegistryKey_GetSubKeyNames : public Test_RegistryKey {};
class Test_RegistryKey_GetValue : public Test_RegistryKey {};
class Test_RegistryKey_SetValue : public Test_RegistryKey {};
class Test_RegistryKey_CreateSubKey : public Test_RegistryKey {};
class Test_RegistryKey_DeleteValue : public Test_RegistryKey {};
