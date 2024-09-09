//
// Created by moham on 9/8/2024.
//

#include "LinkedList.h"
#include <cassert>

template<typename T>
LinkedList<T>::LinkedList() {
    count = 0;
    head = tail = nullptr;
}

template<typename T>
Node<T> *LinkedList<T>::getNode(int index) {
    assert(index < count);
    auto tmp = head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->next;
    }
    return tmp;
}

template<typename T>
bool LinkedList<T>::empty() {
    return count == 0;
}

template<typename T>
void LinkedList<T>::append(T val) {
    if(count == 0){
        head = new Node<T>(val);
        tail = head;
    }
    else {
        tail->next = new Node<T>(val);
        tail = tail->next;
    }
    count++;
}

template<typename T>
void LinkedList<T>::insert(int index, T val) {
    assert(index >= 0 && index < count);

    if(index) {
        Node<T>* tmp = head;
        for (int i = 0; i < index - 1; ++i) {
            tmp = tmp->next;
        }
        auto tempNext = tmp->next;
        tmp->next = new Node<T>(val);
        tmp->next->next = tempNext;
    }
    else{
        auto newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }
    count++;
}

template<typename T>
void LinkedList<T>::erase(int index) {
    assert(index >= 0 && index < count);

    if(index) {
        auto tmp = getNode(index - 1);
        auto nextNode = tmp->next->next;
        delete tmp->next;
        tmp->next = nextNode;
    }
    else{
        auto tmp = head->next;
        delete head;
        head = tmp;
    }
    count--;
}

template<typename T>
T &LinkedList<T>::operator[](int index) {
    assert(index >= 0 && index < count);

    auto tmp = getNode(index);
    return tmp->value;
}

template<typename T>
int LinkedList<T>::size() {
    return count;
}