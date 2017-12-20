# LibWinRegUtil
A modern C++ header only Library for accessing the Windows Registry by encapsulating the Win32 API into intuitive native C++ code. Loosely based on the .Net Registry and RegistryKey libraries to aid in registry data manipulation and extraction by hiding the Win32 C-style method calls.
* Tested on and developed for VC2015 *(This list will expand in the future)*


## Getting Started
### Prerequisites
You will need VC++ 2015 or higher.

### Installation
Download the header file [LibWinRegUtil.h](https://github.com/ossewawiel/LibWinRegUtil/releases/download/0.1/LibWinRegUtil.h) into your project folder or a predefined Include folder, and include it in the required source file in your project as follows:

If placed inside your project folder:
```cpp
#include "LibWinRegUtil.h"
```
If placed in a predefined **Include** folder:
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
    return 0;
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
    return 0;
}
```

# API
## Namespace WinReg
The top namespace for the library.

### Namespace WinReg::Registry
The Registry namespace gives you easy access to common registry tasks as well as acting as a gateway to the RegistryKey class for more specific manipulation and querying of registry items. 

#### Properties
| Name | Description |
| :--- | :--- |
| ClassesRoot() | Returns a RegistryKey class opened as the base key for HKEY_CLASSES_ROOT. |
| CurrentConfig() | Returns a RegistryKey class opened as the base key for HKEY_CLASSES_CURRENT_CONFIG. |
| CurrentUser | Returns a RegistryKey class opened as the base key for HKEY_CURRENT_USER. |
| LocalMachine() | Returns a RegistryKey class opened as the base key for HKEY_LOCAL_MACHINE. |
| Users() | Returns a RegistryKey class opened as the base key for HKEY_USERS. |

#### Methods
| Name | Description |
| :--- | :--- |
| GetBinaryValue(eHKey, wstring, wstring, bool) | Returns a binary value as vector\<BYTE\> for a REG_BINARY value in the specified registry key location and if flagged will throw in case of an exception else it will return an empty vector. |
| GetDwordValue(eHKey, wstring, wstring, bool, DWORD) | Returns a DWORD value for a REG_DWORD value in the specified registry key location and if flagged will throw in case of an exception else it will return the supplied default value. |
| GetExpandedStringValue(eHKey, wstring, wstring, bool, wstring) | Returns a wstring value for a REG_EXPAND_SZ value in the specified registry key location and if flagged will throw an exception else it will return the supplied default value. |