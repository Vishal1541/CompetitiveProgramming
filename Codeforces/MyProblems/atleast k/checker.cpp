#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char * argv[])
{
    setName("compares two strings");
    registerTestlibCmd(argc, argv);
    string ja = ans.readToken();
    string pa = ouf.readToken();
    if (ja.compare(pa)!=0)
        quitf(_wa, "expected %d, found %d", ja, pa);
    quitf(_ok, "answer is %d", ja);
}