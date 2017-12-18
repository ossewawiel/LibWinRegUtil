# LibWinRegUtil
A modern C++ header only Library for accessing the Windows Registry by encapsulating the Win32 API into intuitive native C++ code. Loosely based on the .Net Registry and RegistryKey libraries to aid in registry data manipulation and extraction by hiding the Win32 C-style method calls.
* Tested on and developed for VC2015 *(This list will expand in the future)*


## Getting Started
### Installation
Download the header file [LibWinRegUtil.h](https://github.com/ossewawiel/LibWinRegUtil/releases/download/0.1/LibWinRegUtil.h) into your project folder or a predefined Include folder, and include it in the required source file in your project as follows:

If placed inside your project folder:
```cpp
#include "LibWinRegUtil.h"
```
If placed in anpredefined **Include** folder:
```cpp
#include <LibWinRegtil.h>
```

If you wish to download the latest stable project with tests *(GTEST)* you can get it [here](https://github.com/ossewawiel/LibWinRegUtil/releases/tag/0.1).

### Usage

To get a specific value once-off:
```cpp
#include <string>
#include "LibWinRegUtil.h"

int _tmain(int argc, _TCHAR* argv[])
{
    std::wstring wsRegVal
    { 
        WinReg::Registry::GetStringValue(WinReg::eHKeyUsers, L".DEFAULT\\Software\\ExampleApp", L"ExampleStringValue") 
    };
}
```
To open a key for manipulation:
```cpp
#include <string>
#include "LibWinRegUtil.h"

int _tmain(int argc, _TCHAR* argv[])
{
    WinReg::CRegistryKey regKey
    { 
        WinReg::Registry::Users().OpenSubKey(L".DEFAULT\\Software\\ExampleApp", WinReg::eRegAccessRights::eAccessKeyAllAccess)
    };
    regKey.SetStringValue(L"StringValueName", L"StringValueData");
}
```
