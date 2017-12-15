#pragma once

using namespace WinReg;

class Test_Registry :
	public ::testing::Test
{
public:
	CRegistryKey mRKUsers{ Registry::Users() };
	CRegistryKey mRKClassesRoot{ Registry::ClassesRoot() };
	CRegistryKey mRKCurrentConfig{ Registry::CurrentConfig() };
	CRegistryKey mRKCurrentUser{ Registry::CurrentUser() };
	CRegistryKey mRKLocalMachine{ Registry::LocalMachine() };
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}
};

class Test_Registry_GetStringValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_GetDwordValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_GetQwordValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_GetMultiStringValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_GetBinaryValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_SetStringValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_SetSBinaryValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_SetSDwordValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_SetSQwordValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_SetExpandedStringValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

class Test_Registry_SetMultipleStringValue :
	public ::testing::Test
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};
