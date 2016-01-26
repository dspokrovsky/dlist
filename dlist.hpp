#ifndef DLIST
#define DLIST
#include <cstdio>
#include <iostream>

template <typename T>
class dlist{
public:

    dlist(const T& dt): data_(dt)
    {
        ptr_next = this;
        ptr_prev = this;

    }


    ~dlist(){
    }

    T& data(){
        return data_;
    }
    const T& data() const{
        return data_;
    }

    void dlist_print(){
        dlist* buf = this;
        std::cout << buf->data()<< std::endl;
        while(buf->ptr_next != this){
            buf = buf->ptr_next;
            std::cout << buf->data()<< std::endl;            
        }
    }

    size_t size(){
        dlist* buf = this;
        size_t count = 0;
        count ++;
        while(buf->ptr_next != this){
            buf = buf->ptr_next;
            count ++;
        }
        return count;

    }

    dlist* copy(){
        dlist* new_list = new dlist(this->data());
        dlist* buf = this->ptr_next;
        for(size_t i = 0; i < (this->size()-1); i ++){
            new_list->insert_after(i, buf->data());
            buf = buf->ptr_next;
        }
        return new_list;
    }

    void share(size_t pos1, size_t pos2, dlist* first, dlist* second){
        dlist* buf = this;
        dlist* buf2 = this;
        for( size_t i = 0; i < pos1; i ++){
            buf= buf->ptr_next;
        }
        for( size_t i = 0; i < pos1; i ++){
            buf2= buf2->ptr_next;
        }
        buf->ptr_prev = buf2->ptr_prev;
        buf->ptr_prev->ptr_next = buf2;
        buf2->ptr_prev = buf->ptr_prev;
        buf2->ptr_prev->ptr_next = buf;
        first  = buf;
        second = buf2;
    }


    void insert_after(const size_t& pos,const T& dt){
        dlist * buf = this;
        for( size_t i = 0; i < pos; i ++){
                buf = buf->ptr_next;
            }
        dlist* buf2 = buf->ptr_next;
        dlist* zd = new dlist(dt);
        buf->ptr_next = zd;
        zd->ptr_next = buf2;
        zd->ptr_prev = buf;
        buf2->ptr_prev = zd;
    }

    void insert_before(const size_t& pos,const T& dt){
        dlist * buf = this;
        for( size_t i = 0; i < (pos-1); i ++){
            buf= buf->ptr_next;
        }
        dlist* buf2 = buf->ptr_next;
        dlist zd = new dlist(dt);
        buf->ptr_next = zd;
        zd->ptr_next = buf2;
        zd->ptr_prev = buf;
        buf2->ptr_prev = zd;
    }

    dlist* access(const size_t& pos){
        dlist* buf = this;
        for(size_t i = 0; i < pos; i ++){
            buf = buf->ptr_next;
        }
        return buf;
    }
    //в случае успеха возврашает указатель на начало списка, иначе NULL
    dlist* remove(const T& dt){
        dlist* buf = this;
        if (buf->data() == dt){
            buf->ptr_prev->ptr_next = buf->ptr_next;
            buf->ptr_next->ptr_prev = buf->ptr_prev;
            dlist*buf2 = buf->ptr_prev;
            delete buf;
            return buf2;
        }
        while(buf->ptr_next != this){
            buf = buf->ptr_next;
            if(buf->data() == dt ){
                buf->ptr_prev->ptr_next = buf->ptr_next;
                buf->ptr_next->ptr_prev = buf->ptr_prev;
                delete buf;
                return this;
            }
        }
        return NULL;
    }


    unsigned int index;


    dlist* ptr_next;
    dlist* ptr_prev;
private:
    T data_;
};

template <typename T>
dlist<T>* combine(dlist<T>* first, dlist<T>* second){
    dlist<T>* new_list;
    new_list = first->copy();

    dlist<T>* buf = second;
    for(size_t i = 0; i < (second->size()); i ++){
        new_list->insert_after(second->size()+i, buf->data());
        buf = buf->ptr_next;
    }
    return new_list;
}


#endif // DLIST

