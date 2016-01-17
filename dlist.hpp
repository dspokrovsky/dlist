#ifndef DLIST
#define DLIST
#include <cstdio>

template <typename T>
class dlist{
public:
    dlist(const T& dt):
        data(dt)
    {

    }
    ~dlist(){
        dlist* buf = this;

        while(buf->ptr_next != NULL){
            buf = buf->ptr_next;
        }
        dlist* prev_buf;
        while(buf->ptr_prev != NULL){

            prev_buf = buf->ptr_prev;
            delete buf;
            buf = prev_buf;
        }
    }

    dlist* emplace(const T& dt){
        dlist* buf = this;
        while(buf->ptr_next != NULL){
            buf = buf->ptr_next;
        }
        dlist* zd = new dlist(dt);
        buf->ptr_next = zd;
        zd->ptr_prev = buf;
        return zd;
    }

    T data;

    unsigned int index;

private:
    dlist* ptr_next = NULL;
    dlist* ptr_prev = NULL;
};



#endif // DLIST

