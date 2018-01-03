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
| **ClassesRoot()** | Returns a RegistryKey class opened as the base key for HKEY_CLASSES_ROOT. |
| **CurrentConfig()** | Returns a RegistryKey class opened as the base key for HKEY_CLASSES_CURRENT_CONFIG. |
| **CurrentUser()** | Returns a RegistryKey class opened as the base key for HKEY_CURRENT_USER. |
| **LocalMachine()** | Returns a RegistryKey class opened as the base key for HKEY_LOCAL_MACHINE. |
| **Users()** | Returns a RegistryKey class opened as the base key for HKEY_USERS. |

#### Methods
| Name | Description |
| :--- | :--- |
| **GetBinaryValue(eHKey, wstring, wstring, bool)** | Returns a binary value as vector\<BYTE\> for a REG_BINARY value in the specified registry key location and if flagged will throw in case of an exception else it will return an empty vector. |
| **GetDwordValue(eHKey, wstring, wstring, bool, DWORD)** | Returns a DWORD value for a REG_DWORD value in the specified registry key location and if flagged will throw in case of an exception else it will return the supplied default value. |
| **GetExpandedStringValue(eHKey, wstring, wstring, bool, wstring)** | Returns a wstring value for a REG_EXPAND_SZ value in the specified registry key location and if flagged will throw an exception else it will return the supplied default value. |
| **GetMultiStringValue(eHKey, wstring, wstring, bool)** | Returns a wstring vector for a REG_MULTI_SZ value in the specified registry key location and if flagged will throw in case of an exception else it will return an empty vector. |
| **GetQwordValue(eHKey, wstring, wstring, bool, ULONGLONG)** | Returns a ULONGLONG value for a REG_QWORD value in the specified registry key location and if flagged will throw in case of an exception else it will return the supplied default value. |
| **GetStringValue(eHKey, wstring, wstring, bool, wstring)** | Returns a wstring value for a REG_SZ value in the specified registry key location and if flagged will throw in case of an exception else it will return the supplied default value. |
| **SetBinaryValue(eHKey, wstring, wstring, vector\<BYTE\>)** | Sets the value of a REG_BINARY value in the specified registry key location by accepting a BYTE vector. If the value does not yet exist it will be created. |
| **SetDwordValue(eHKey, wstring, wstring, DWORD)** | Sets the value of a REG_DWORD value in the specified registry key location. If the value does not yet exist it will be created. |
| **SetExpandedStringValue(eHKey, wstring, wstring, wstring)** | Sets the value of a REG_EXPAND_SZ value in the specified registry key location by accepting a wstring. If the value does not yet exist it will be created. |
| **SetMultiStringValue(eHKey, wstring, wstring, vector\<wstring\>)** | Sets the value of a REG_MULTI_SZ value in the specified registry key location by accepting a wstring vector. If the value does not yet exist it will be created. |
| **SetQwordValue(eHKey, wstring, wstring, ULONGLONG)** | Sets the value of a REG_QWORD value in the specified registry key location by accepting a ULONGLONG. If the value does not yet exist it will be created. |
| **SetStringValue(eHKey, wstring, wstring, wstring)** | Sets the value of a REG_SZ value in the specified registry key location by accepting a wstring. If the value does not yet exist it will be created. |

### Class WinReg::RegistryKey
A class created for and attached to a specific registry key that enables more granular manipulation of the key, its values and sub keys.

#### Constructor
| Name | Description |
| :--- | :---|
| **CRegistryKey(eHkey)** | Returns an open read-only base key for the specified eHKey. |

#### Properties
| Name | Type | Description |
| :--- | :--- | :--- |
| **Name()** | Get | Returns a wstring full path name of the current open key. |
| **SubKeyCount()** | Get | Returns an int count of the usb keys in the current open key. |
| **ValueCount()** | Get | Returns an int count of the values in the current open key. |
| **View()** | Get | Returns an eRegView view type of the current open key. |

#### Methods
| Name | Description |
| :--- | :--- |
| **CreateSubKey(wstring, eRegAccessRights)** | Creates a new CRegistryKey sub key under the current open key with the specified access rights (Defaults to eAccessKeyRead). If the key already exists it returns the existing key. |
| **DeleteSubKey(wstring)** | Deletes the specified sub key under the current open key. |
| **DeleteValue(wstring)** | Deletes the specified value under the current open key. |
| **Flush()** | Flushes the current current open key ensuring all changes as saved to disk. |
| **GetBinaryValue(wstring, bool)** | Returns a binary value as vector\<BYTE\> for a REG_BINARY value in the current open key and if flagged will throw in case of an exception else it will return an empty vector. |
| **GetDwordValue(wstring, bool, DWORD)** | Returns a DWORD value for a REG_DWORD value in the current open key and if flagged will throw in case of an exception else it will return the supplied default value. |
| **GetExpandedStringValue(wstring, bool, wstring)** | Returns a wstring value for a REG_EXPAND_SZ value in the current open key and if flagged will throw an exception else it will return the supplied default value. |
| **GetMultiStringValue(wstring, wstring, bool)** | Returns a wstring vector for a REG_MULTI_SZ value in the current open key and if flagged will throw in case of an exception else it will return an empty vector. |
| **GetQwordValue(wstring, bool, ULONGLONG)** | Returns a ULONGLONG value for a REG_QWORD value in the current open key and if flagged will throw in case of an exception else it will return the supplied default value. |
| **GetStringValue(wstring, bool, wstring)** | Returns a wstring value for a REG_SZ value in the current open key and if flagged will throw in case of an exception else it will return the supplied default value. |
| **GetSubKeyNames()** | Returns a wstring vector of the sub key names in the current open key. |
| **GetValueKind(wstring)** | Returns the eRegValueKind kind of the specified value in the current open key. |
| **GetValueNames()** | Returns a wstring vector of the value names in the current open key. |
| **OpenSubKey(wstring, eRegAccessRights)** | Opens the specified subkey with the supplied access rights (Defaults to eAccessKeyRead) under the current open key. Will throw if the key does not exist. |
| **SetBinaryValue(wstring, vector\<BYTE\>)** | Sets the value of a REG_BINARY value in the current open key by accepting a BYTE vector. If the value does not yet exist it will be created. |
| **SetDwordValue(wstring, DWORD)** | Sets the value of a REG_DWORD value in the current open key. If the value does not yet exist it will be created. |
| **SetExpandedStringValue(wstring, wstring)** | Sets the value of a REG_EXPAND_SZ value in the current open key by accepting a wstring. If the value does not yet exist it will be created. |
| **SetMultiStringValue(wstring, vector\<wstring\>)** | Sets the value of a REG_MULTI_SZ value in the current open key by accepting a wstring vector. If the value does not yet exist it will be created. |
| **SetQwordValue(wstring, ULONGLONG)** | Sets the value of a REG_QWORD value in the current open key by accepting a ULONGLONG. If the value does not yet exist it will be created. |
| **SetStringValue(wstring, wstring)** | Sets the value of a REG_SZ value in the current open key by accepting a wstring. If the value does not yet exist it will be created. |

### Enumerators
#### WinReg::eHKey
| Name | Value | Description |
| :--- | ---: | :--- |
| eHkeyNotDefined |	0 | Not defined and not mapping to any HKEY. |
| eHKeyClassesRoot | 1 | Mapping to HKEY_CLASSES_ROOT. |
| eHKeyCurrentConfig | 2 | Mapping to HKEY_CURRENT_CONFIG. |
| eHKeyCurrentUser | 3 | Mapping to HKEY_CURRENT_USER. |
| eHKeyLocalMachine | 4 | Mapping to HKEY_LOCAL_MACHINE. |
| eHKeyUsers | 5 | Mapping to HKEY_USERS. |

#### WinReg::eRegAccessRights
| Name | Value | Description |
| :--- | ---: | :--- |
| eAccessKeyAllAccess | 0xF003F | Combines the STANDARD_RIGHTS_REQUIRED, KEY_QUERY_VALUE, KEY_SET_VALUE, KEY_CREATE_SUB_KEY, KEY_ENUMERATE_SUB_KEYS, KEY_NOTIFY, and KEY_CREATE_LINK access rights. Maps to KEY_ALL_ACCESS. |
| eAccessKeyCreateSubKey | 0x0004 | Required to create a subkey of a registry key. Maps to KEY_CREATE_SUB_KEY. |
| eAccessKeyEnumerateSubKeys | 0x0008 | Required to enumerate the subkeys of a registry key. Maps to KEY_ENUMERATE_SUB_KEYS. |
| eAccessKeynotify | 0x0010 | Required to request change notifications for a registry key or for subkeys of a registry key. Maps to KEY_NOTIFY . |
| eAccessKeyQueryValue | 0x0001 | Required to query the values of a registry key. Maps to KEY_QUERY_VALUE. |
| eAccessKeyRead | 0x20019 | Combines the STANDARD_RIGHTS_READ, KEY_QUERY_VALUE, KEY_ENUMERATE_SUB_KEYS, and KEY_NOTIFY values. Maps to KEY_READ. |
| eAccessKeySetValue | 0x0002 | Required to create, delete, or set a registry value. Maps to KEY_SET_VALUE. |
| eAccessKeyWrite | 0x20006 | Combines the STANDARD_RIGHTS_WRITE, KEY_SET_VALUE, and KEY_CREATE_SUB_KEY access rights. Maps to KEY_WRITE. |

#### WinReg::eRegView
| Name | Value | Description |
| :--- | ---: | :--- |
| eViewDefault | 0x0000 | Current default setting. |
| eViewWow6432 | 0x0200 | Viewing 32 bit entry. |
| eViewWow6464 | 0x0100 | Viewing 64 bit entry. |
| eViewUndefined | 0x9999 | View option not set. |

#### WinReg::eRegValueKind
| Name | Value | Description |
| :--- | ---: | :--- |
| eValueKindUnknown | 0 | Default setting. |
| eValueKindString | 1 | Map to REG_SZ |
| eValueKindExpandedString | 2 | Map to REG_EXPAND_SZ. |
| eValueKindBinary | 3 | Map to REG_BINARY. |
| eValueKindDword | 4 | Map to REG_DWORD. |
| eValueKindMultiString | 7 | Map to REGNULTI_SZ |
| eValueKindQWord | 11 | Map to REG_QWORD |



