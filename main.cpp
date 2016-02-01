#include <iostream>
#include "string"
#include <books.hpp>
#include "list.hpp"

using namespace std;

int main()
{
/*
    Book a;
    a.book = "first";
    a.fio = "fir";
*/
    dlist::list<int> k;

    k.insert(0,1);
    k.insert(0,2);
    k.insert(0,3);

    return 0;
}

