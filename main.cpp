#include <iostream>
#include <dlist.hpp>

using namespace std;

int main()
{

    dlist<int> k(1);
    k.emplace(2);
    k.emplace(2);
    k.emplace(2);

    return 0;
}

