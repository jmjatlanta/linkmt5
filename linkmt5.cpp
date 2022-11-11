#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include "linkmt5.h"
#include "SocketServer.h"
#include "SocketClient.h"

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include <vector>
#include <string>
#include <iostream>
#include <memory>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")

static int isServer = -1;

static std::shared_ptr<SocketServer> socketServer;
static std::shared_ptr<SocketClient> socketClient;

/****
 * @return true(1) if this is a server
 */
_DLLAPI int __stdcall LinkIsServer()
{
    return isServer;
}

/***
 * @brief start the server
 * @param port the port to bind to
 * @return true on success
 */
_DLLAPI int __stdcall LinkStartServer(int port)
{
	socketServer = std::make_shared<SocketServer>(port);
    isServer = 1;
    return 1;
}

std::string wchar_to_string(const wchar_t& in)
{
	char buf[65535];
	auto length = wcstombs(buf, &in, 65535);
	return std::string(buf);
}

/***
 * @brief start the client
 * @param host the host to attempt to connect to in format "ip:port"
 * @return true on success
 */
_DLLAPI int __stdcall LinkStartClient(wchar_t& host, wchar_t& port)
{
	socketClient = std::make_shared<SocketClient>(wchar_to_string(host), wchar_to_string(port));
    isServer = 0;
    return 1;
}

/****
 * @brief stop the server or client
 * @return true on success
 */
_DLLAPI int __stdcall LinkStopServerClient()
{
	socketServer = nullptr;
	socketClient = nullptr;
    isServer = -1;
    return 1;
}

std::vector<unsigned char> Serialize(const MqlTick& in)
{
	std::vector<unsigned char> ret;
	return ret;
}

/****
 * @brief send a tick
 * @param symbol the symbol
 * @tick the tick
 * @return true on success
 */
_DLLAPI int __stdcall LinkSendTick(wchar_t& symbol, MqlTick tick)
{
	if (socketServer == nullptr)
		return 0;

	socketServer->SendToAll(Serialize(tick));
    return 1;
}

