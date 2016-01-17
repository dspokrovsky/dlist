#include <iostream>
//#include <dlist.hpp>
#include <dlist_easy.hpp>

using namespace std;

int main()
{

    //dlist<int> k(1);
    dlist_easy<int> k;
    for(int i = 0; i < 10; i ++){
        k.emplace(k.end(),i);
    }
    auto p = k.end();
   // p++;
    //k.insert_before(p, 10);
    k.insert_after(p, 30);


    for(auto i=k.begin(); i != k.end(); i ++){
        cout << *i<<std::endl;
    }

    return 0;
}

