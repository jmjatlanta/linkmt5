CXX=x86_64-w64-mingw32-g++
LFLAGS=-lws2_32

%.o:%.cpp
	$(CXX) -c $^

all: TestMT5.exe LinkMT5.dll

TestMT5.exe: main.o linkmt5.o
	$(CXX) -static -o $@ $^ $(LFLAGS)

LinkMT5.dll: linkmt5.o
	$(CXX) -shared -o $@ $^ $(LFLAGS)

clean:
	$(RM) *.o
	$(RM) TestMT5.exe
	$(RM) LinkMT5.dll
