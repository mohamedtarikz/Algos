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
    auto* newNode = new Node<T>(val);

    if(head == nullptr){
        head = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

template<typename T>
void LinkedList<T>::insert(int index, T val) {
    assert(index >= 0 && index < count);
    Node<T> newNode(val);
    if(index) {
        Node<T>* tmp = head;
        for (int i = 0; i < index - 1; ++i) {
            tmp = tmp->next;
        }
        newNode.next = tmp->next;
        tmp->next = &newNode;
    }
    else{
        newNode.next = head;
        head = &newNode;
    }
}

template<typename T>
void LinkedList<T>::erase(int index) {
    assert(index >= 0 && index < count);

    auto tmp = getNode(index-1);
    auto nextNode = tmp->next->next;
    delete tmp->next;
    tmp->next = nextNode;
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