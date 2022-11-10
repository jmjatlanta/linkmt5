Build a DLL for MT5

It should handle all the events, and echo their details to listeners.

On initialization, it should bind to a TCP port, or in the case of a client, attempt to connect to a server.

On Tick it should forward the tick information to any listeners. The same for other events.


Messages should be versioned, and/or be in JSON

Perhaps the clients should state their version.
