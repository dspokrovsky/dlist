#include <iostream>
#include <dlist.hpp>
//#include <dlist_easy.hpp>
#include "string"
using namespace std;

int main()
{
    struct T{
        string book;
        string fio;
        bool operator==(const T& dt2)
        {
            return (this->book == dt2.book);
        }
        bool operator!=(const T& dt2){
            return (this->book != dt2.book);
        }
        ostream& operator<<(ostream & os){
            os << this->book << "  " << this->fio <<endl;
            return os;
        }
    };



    struct T a;
    a.book = "first";
    a.fio = "fir";

    dlist<T> k(a);
    cout << a;

    /*
    k.insert_after(1,2);
    k.insert_after(1,2);
    k.insert_after(10,3);
    k.dlist_print();
    cout << " ***** "<<endl;

    dlist<int>* cop_k;
    cop_k = k.copy();
    cop_k->dlist_print();
    cout << " *****gogog "<<endl;
    dlist<int>* cop_k2;
    cop_k2 = combine(cop_k,cop_k);
    cop_k2->dlist_print();
*/

    return 0;
}

