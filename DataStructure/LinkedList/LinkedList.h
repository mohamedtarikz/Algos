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
    class iterator{
        Node<T>* ptr;
    public:
        iterator(Node<T>* p) : ptr(p){}
        T& operator*(){return ptr->value;}
        iterator& operator++(){return ptr->next;}
        bool operator!=(const iterator& other){return ptr != other.ptr;}
    };
    LinkedList();
    bool empty();
    void append(T val);
    void insert(int index, T val);
    void erase(int index);
    T& operator[](int index);
    iterator begin(){
        return head;
    }
    iterator end(){
        return tail->next;
    }
    int size();
};

#include "LinkedList.tpp"

#endif //LINKEDLIST_LINKEDLIST_H
