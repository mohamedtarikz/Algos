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
    LinkedList();
    bool empty();
    void append(T val);
    void insert(int index, T val);
    void erase(int index);
    T& operator[](int index);
    int size();
};


#endif //LINKEDLIST_LINKEDLIST_H
