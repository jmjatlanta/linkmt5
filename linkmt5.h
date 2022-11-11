#pragma once

#include <cstdint>
#include <vector>

#define _DLLAPI extern "C" __declspec(dllexport)

struct MqlTick
{
	int64_t time;
	double	bid;
	double	ask;
	double	last;
	int64_t	volume;	
};

_DLLAPI int __stdcall LinkIsServer();
_DLLAPI int __stdcall LinkStartServer(int port);
_DLLAPI int __stdcall LinkStartClient(wchar_t& host, wchar_t& client);
_DLLAPI int __stdcall LinkStopServerClient();
_DLLAPI int __stdcall LinkSendTick(wchar_t& symbol, MqlTick tick);

std::vector<unsigned char> Serialize(const MqlTick& in);
