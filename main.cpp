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

    k.insert(k.head(),1);

    k.insert(k.find(1),2);
    dlist::el<int>* z= k.find(2);
    k.insert(k.find(2),3);
    k.insert(k.find(3),4);
    k.insert_before(k.find(4),5);
    //cout << k << endl;
    dlist::list<int> t(k.split(k.find(1),k.find(3)));






    return 0;
}

