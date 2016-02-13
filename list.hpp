#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
namespace dlist {

    template<typename T>
    class el{
    public:
        el(const T& dt)/*: data(dt)*/{
            data = new T(dt);
        }
        ~el(){
            delete data;
        }

        el* next = NULL;
        el* prev = NULL;

        T* data;
        void operator= (const el<T>& dt){
            this->next = dt.next;
            this->prev = dt.prev;
            this->data = dt.data;
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
        list(const T& dt)
        {
            insert(head_, dt);
        }

        list(list& other){
            if(other.head() != NULL){
                this->insert(other.head(),*other.head()->data);
                auto buf = other.head()->next;
                el<T>* buf2 = this->head();
                while(buf != other.head()){
                    this->insert(buf2,*buf->data);
                    buf = buf->next;
                    buf2 = buf2->next;
                }

            }

        }

        ~list(){
            if(head_!=NULL){
                el<T>* buf = head_;
                el<T>* buf2;
                while(buf->next!=head_){
                    buf2 = buf;
                    buf = buf->next;
                    delete buf2;
                }
                delete buf;
                head_ = NULL;
            }

        }
        void print(){
            auto buf = head_;
            while(buf->next!= head_){
                cout << *buf->data<< endl;
                buf = buf->next;
            }
            cout << *buf->data<< endl;
        }


        //вставка элемента по указателю, если вставка не удалась, то вернет -1
        int insert(el<T>* ptr, const T& dt){
            if ( head_ == NULL){
                head_ = new el<T>(dt);
                head_->prev = head_;
                head_->next = head_;
                count_++;
                return 0;
            }
            el<T>* buf = head_;
            for( size_t i = 0; i <= count_; i ++){
                if(buf == ptr){
                    break;
                }else{
                    buf= buf->next;
                }
                if (i == count_) return -1;
            }
            buf = new el<T>(dt);
            buf->next = ptr->next;
            ptr->next =buf;
            buf->prev = ptr;
            buf->next->prev = buf;
            count_++;
            return 0;
        }

        void insert_before(el<T>* ptr, const T& dt){
            insert(ptr->prev, dt);
        }

        T& get(std::size_t index){
            el<T>* buf = head_;
            for(std::size_t i =0; i < index; i ++){
                buf++;
            }
            return buf->data;
        }
        T& get(el<T>* ptr){
            return ptr->data;
        }

        el<T>* find(const T& dt){
            if(*head_->data == dt) return head_;
            el<T>* buf = head_->next;
            while(buf != head_){
                if (dt == *buf->data) return buf;
                buf = buf->next;
            }
            return NULL;
        }

        void remove(const T& dt){
            el<T>* del = find(dt);
            if (del !=NULL && del != head_) {
                del->prev->next = del->next;
                del->next->prev = del->prev;
                count_--;
                delete del;
            }else{
                if(del == NULL){
                }else{
                    if (del == head_){
                        del->prev->next = del->next;
                        del->next->prev = del->prev;
                        head_ = head_->next;
                        delete del;
                        count_--;
                    }
                }
            }
        }

        bool merge(el<T>*ptr, list& other){
            if (check_ptr(ptr)) return false;
            if (other.head()==NULL) return false;
            ptr->next->prev =other.head()->prev;
            other.head()->prev->next = ptr->next;
            ptr->next = other.head();
            other.head()->prev = ptr;
            this->count_ += other.count_;
            other.head_ = NULL;
            return true;
        }
        //делит текущий кольцевой список на 2 списка,
        //если указатели указаны не верно = возвращает пустой список
        list& split(el<T>*ptr1,el<T>*ptr2){
            list k;
            auto buf = this->head();
            size_t i = 1;
            while  ( buf != ptr1){
                if (i > this->count_) return k;
                i++;
                buf = buf->next;
            }
            i = 1;
            buf = this->head();
            while  ( buf != ptr2){
                if (i > this->count_) return k;
                i++;
                buf = buf->next;
            }

            size_t listsize =1;
            buf = ptr1;
            bool tr = false;
            while (buf != ptr2){
                listsize++;
                if (buf == head()) tr = true;
                buf = buf->next;
            }

            if (tr) {
                k.head_ = ptr2->next;
                k.count_ = count_ - listsize;
                count_ = listsize;
            }else{
                k.head_ = ptr1;
            }
            ptr1->prev->next = ptr2->next;
            ptr2->next->prev = ptr1->prev;
            ptr1->prev = ptr2;
            ptr2->next = ptr1;
            return k;


        }

        std::size_t size(){
            return count_;
        };

        el<T>* head(){
            return head_;
        }

private:

        bool check_ptr(el<T>* ptr){
            auto buf = this->head()->next;
            while( buf != this->head()){
                if (buf == ptr) return true;
                buf = buf->next;
            }
            return false;
        }

        el<T>* head_ = NULL;
        std::size_t count_ = 0;

    };
}
#endif // LIST_HPP
