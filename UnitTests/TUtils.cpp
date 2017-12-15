#include "stdafx.h"
#include "TUtils.h"

std::wstring TUtils::ErrMsg(const std::exception & ex)
{
	return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>().from_bytes(std::string(ex.what()));
}

bool TUtils::InString(const std::wstring &mainString,  const std::wstring & subString)
{
	if(mainString.find(subString) == std::wstring::npos)
		return false;

	return true;
}
