#include <iostream>
#include "string"
#include <books.hpp>
#include "list.hpp"


using namespace std;

int main()
{

    int* p2 = new int(1);
    delete p2;

    Book a;
    a.book = "first";
    a.fio = "fir";


    dlist::el<Book>* el = new dlist::el<Book>(a);

    delete el;

    dlist::list<Book>* boom = new dlist::list<Book>(a);
    boom->insert(boom->head(),a);
    boom->print();

    delete boom;

    boom->print();
    {
    dlist::list<int> k;
    k.insert(k.head(),1);
    k.insert(k.find(1),2);
    dlist::el<int>* z= k.find(2);
    k.insert(k.find(2),3);
    k.insert(k.find(3),4);
    k.insert_before(k.find(4),5);

    k.print();

    dlist::list<int> k2(k);

    k.merge(k.head(),k2);
    //cout << k << endl;

    dlist::list<int>* ptr = new dlist::list<int>(k);


    delete ptr;


    }




    return 0;
}

