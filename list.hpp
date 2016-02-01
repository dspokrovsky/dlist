#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
namespace dlist {

    template<typename T>
    class el{
    public:
        el(const T& dt): data(dt){

        }

        el* next = NULL;
        el* prev = NULL;
        T data;
        void operator= (const el<T>& dt){
            this->next = dt.next;
            this->prev = dt.prev;
            this->data = dt.data;
        }
        el* operator++(){
            return this->next;
        }
        el* operator--(){
            return this->prev;
        }
    };

    template<typename T>
    class list
    {
    public:
        list(){
            head_ = NULL;
            count_ = 0;
        }
/*
        list(const list& other){
            head_ = new el;
            head_->data = other.head_->data;
            head_->next = NULL;
            head_->prev = NULL;
            el<T>* lst = head_;
            count_ = 1;
            el<T>* buf = other.head_->next;
            while (buf != other.head_) {
                count_++;
                el<T>* buf2 = new el;
                buf2->data = buf->data;
                lst->next  = buf2;
                buf2 = lst;
                buf2->prev


            }
        }*/

        ~list(){
            el<T>* buf = head_;
            el<T>* buf2;
            for( std::size_t  i  = 0; i < count_; i ++ ){
                buf2 = buf->next;
                delete buf;
                buf = buf2;
            }
        }



        void insert(const std::size_t& pos, const T& dt){
            if (this->head_ == NULL){
                el<T>* buf = new el<T>(dt);
                head_ = buf;
                head_->next = head_;
                head_->prev = head_;
                count_++;
            }else{
                auto buf = this->head_;
                size_t my_pos = pos% count_;
                for( size_t i = 0; i < my_pos; i ++){
                        buf = buf->next;
                    }
                auto buf2 = buf;
                el<T>* zd = new el<T>(dt);
                buf->next = zd;
                zd->next = buf2;
                zd->prev = buf;
                buf2->prev = zd;
                count_++;
            }
           /* if (size() == 0) {
                el<T>* buf = new el<T>;
                head_ = buf;
                head_->data = dt;
                head_->next = head_;
                head_->prev = head_;
                count_++;
            }else{
                std::size_t my_pos = pos%this->size();
                el<T>* buf = this->head_;
                for(std::size_t i = 0; i < my_pos; i++){
                    buf++;
                }
                el<T>* buf2 = new el<T>;
                buf2->data = dt;
                el<T>* remember = buf->next;
                buf->next = buf2;
                buf->next->next = remember;
                remember->prev = buf2;
                buf->next->prev = buf;
            }*/
        }

        void insert_after(el<T>* ptr, const T& dt);

        T& get(std::size_t index){
            el<T>* buf = head_;
            for(std::size_t i =0; i < index; i ++){
                buf++;
            }
            return buf->data;
        }

        el<T>* find(const T& dt);

        void remove(const T& dt);

        list merge(const list& other);

        list split(const std::size_t pos,const std::size_t amount);

        std::size_t size(){
            return count_;
        };
        const el<T>* head()const{
            return head_;
        }

private:
        el<T>* head_ = NULL;
        std::size_t count_ = 0;

    };
}
#endif // LIST_HPP
