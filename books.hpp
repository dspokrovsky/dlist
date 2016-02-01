#ifndef BOOKS
#define BOOKS
#include <iostream>
#include "string.h"


using namespace std;
struct Book{
    string book;
    string fio;

    bool operator==(const Book& dt2)
    {
        return (this->book == dt2.book);
    }

    bool operator!=(const Book& dt2){
        return (this->book != dt2.book);
    }
    friend ostream& operator<<(ostream& os, const Book& dt);
};
ostream& operator<<(ostream & os, const Book& dt){
    os << dt.book << "  " << dt.fio <<endl;
    return os;
}
#endif // BOOKS

