//+------------------------------------------------------------------+
//|                                                      testdll.mq5 |
//|                                                       jmjatlanta |
//|                                            http://jmjatlanta.com |
//+------------------------------------------------------------------+
#property copyright "jmjatlanta"
#property link      "http://jmjatlanta.com"
#property version   "1.00"

#import "LinkMT5.dll"
int LinkIsServer();
int LinkStartServer(int port);
int LinkStartClient(string host);
int LinkStopServerClient();
int LinkSendTick(string symbol, MqlTick tick);
#import

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
{
    // If you want to be the server:
    if (LinkStartServer(1234))
    // If you wnat to be the client:
    //if (LinkStartClient("127.0.0.1:1234"))
        return INIT_SUCCESS;
    return INIT_FAILED;
}

//+------------------------------------------------------------------+
//| Expert deinitialization function                                 |
//+------------------------------------------------------------------+
void OnDeinit(const int reason)
{
    LinkStopServerClient();  
}

//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick()
{
    if (LinkIsServer())
    {
        MqlTick last_tick;
        string sym = Symbol();
        if(SymbolInfoTick(sym, last_tick))
        {
            // send tick to network
            LinkSendTick(sym, last_tick);
        }
    }
}

//+------------------------------------------------------------------+
//| Trade function                                                   |
//+------------------------------------------------------------------+
void OnTrade()
{
   
}
