//
// Created by moham on 9/8/2024.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"
#include <cassert>

template<typename T>
class LinkedList {
    int count;
    Node<T>* head;
    Node<T>* tail;

    Node<T>* getNode(int index){
        assert(index < count);
        auto tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->next;
        }
        return tmp;
    }

public:
    class Iterator{
        Node<T>* ptr;
    public:
        Iterator(Node<T>* p) : ptr(p){}
        T& operator*(){return ptr->value;}
        Iterator& operator++(){return ptr->next;}
        bool operator!=(const Iterator& other){return ptr != other.ptr;}
    };

    LinkedList(){
        count = 0;
        head = tail = nullptr;
    }

    bool empty(){
        return count == 0;
    }

    void append(T val){
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

    void insert(int index, T val){
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

    void erase(int index){
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

    T& operator[](int index){
        assert(index >= 0 && index < count);

        auto tmp = getNode(index);
        return tmp->value;
    }

    Iterator begin(){
        return head;
    }

    Iterator end(){
        return tail->next;
    }

    int size(){
        return count;
    }
};

#endif //LINKEDLIST_LINKEDLIST_H
