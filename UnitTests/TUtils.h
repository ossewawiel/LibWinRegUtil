#pragma once

namespace TUtils
{
	std::wstring ErrMsg(const std::exception &ex);
	bool InString(const std::wstring &mainString, const std::wstring &subString);
}