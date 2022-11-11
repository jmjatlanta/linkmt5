CXX=x86_64-w64-mingw32-g++
CXX_FLAGS=-I./thirdparty/SocketServer
LFLAGS=-lws2_32
SOCKETSERVER_OBJS=thirdparty/SocketServer/SocketServer.o thirdparty/SocketServer/SocketClient.o
%.o:%.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

all: TestMT5.exe LinkMT5.dll

TestMT5.exe: main.o linkmt5.o $(SOCKETSERVER_OBJS)
	$(CXX) -static -o $@ $^ $(LFLAGS)

LinkMT5.dll: linkmt5.o $(SOCKETSERVER_OBJS)
	$(CXX) -shared -o $@ $^ $(LFLAGS)

clean:
	$(RM) *.o
	$(RM) TestMT5.exe
	$(RM) LinkMT5.dll
