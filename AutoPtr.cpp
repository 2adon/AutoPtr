#include "AutoPtr.hpp"

int main(int argc, char* argv, char* envp)
{
    int x = 10;
    int y = 12;
    AutoPtr<int> ap = &x;
    AutoPtr<int> bp = &y;
    ap = bp;

    std::cout << *ap;

    return 0;
}
