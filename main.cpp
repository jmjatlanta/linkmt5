#include "linkmt5.h"

#include <iostream>

static int counter = 0;

template<class T>
bool Verify_eq(const T& lhs, const T& rhs)
{
    counter++;
    if (lhs == rhs)
    {
        return true;
    }
    std::cerr << "Test " << counter << " Verify failed: " << lhs << " != " << rhs << "\n";
    return false;
}

bool TestServer()
{
    int val = LinkIsServer();
    Verify_eq(val, -1);
    val = LinkStartServer(1234);
    Verify_eq(val, 1);
    val = LinkIsServer();
    Verify_eq(val, 1);
    val = LinkStopServerClient();  
    Verify_eq(val, 1);
    val = LinkIsServer();
    Verify_eq(val, -1);
    return true;
}

int main(int argc, char** argv)
{
    TestServer();

    return 1;
}
