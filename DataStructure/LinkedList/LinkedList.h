//
// Created by moham on 9/8/2024.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"

template<typename T>
class LinkedList {
    int count;
    Node<T>* head;
    Node<T>* tail;
    Node<T>* getNode(int index);
public:
    class Iterator{
        Node<T>* ptr;
    public:
        Iterator(Node<T>* p) : ptr(p){}
        T& operator*(){return ptr->value;}
        Iterator& operator++(){return ptr->next;}
        bool operator!=(const Iterator& other){return ptr != other.ptr;}
    };
    LinkedList();
    bool empty();
    void append(T val);
    void insert(int index, T val);
    void erase(int index);
    void sort(bool(*comp)(T a, T b) = [](T a, T b){return a < b;}){
        auto outer = head;
        for (int i = 0; i < count; ++i) {
            auto inner = outer->next;
            for (int j = i + 1; j < count; ++j) {
                if (comp(inner->value, outer->value)){
                    T temp = inner->value;
                    inner->value = outer->value;
                    outer->value = temp;
                }
                inner = inner->next;
            }
            outer = outer->next;
        }
    }
    T& operator[](int index);
    Iterator begin(){
        return head;
    }
    Iterator end(){
        return tail->next;
    }
    int size();
};

#include "LinkedList.tpp"

#endif //LINKEDLIST_LINKEDLIST_H
