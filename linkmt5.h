#pragma once

#include <cstdint>

#define _DLLAPI extern "C" __declspec(dllexport)

struct SocketClient
{
	uint8_t status;
	uint16_t sequence;
	uint32_t sock;
};

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
_DLLAPI int __stdcall LinkStartClient(wchar_t& host);
_DLLAPI int __stdcall LinkStopServerClient();
_DLLAPI int __stdcall LinkSendTick(wchar_t& symbol, MqlTick tick);

