//how easy to make your laboratoried work
//dont try to trick you teacher in this way
#ifndef DLIST_EASY
#define DLIST_EASY
#include <list>
#include <iterator>

template <typename T>
class dlist_easy: public std::list<T>
{
public:
    typename std::list<T>::iterator insert_after(typename std::list<T>::iterator pos, const T& dt){
        if ( pos == this->end() ) return this->insert(pos,dt);
        pos++;
        return this->insert(pos,dt);
    }

    typename std::list<T>::iterator insert_before(typename std::list<T>::iterator pos, const T& dt){
        return this->insert(pos,dt);
    }

};


#endif // DLIST_EASY

