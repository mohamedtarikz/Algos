//
// Created by moham on 9/1/2024.
//

#ifndef ARRAYLIST_MYVECTOR_H
#define ARRAYLIST_MYVECTOR_H

#include "assert.h"

template <typename t> class MyVector {
    int elements, capacity;
    static t* arr;
    void expand(){
        capacity *= 2;
        t *tmp = new t[capacity];
        for (int i = 0; i < elements; ++i) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }
public:
    class Iterator{
        t* current_ptr;
    public:
        Iterator(t* ptr = &arr[0]):current_ptr(ptr){}
        t& operator*(){return *current_ptr;}
        Iterator& operator++(){++current_ptr; return *this;}
        bool operator!=(const Iterator& other){return current_ptr != other.current_ptr;}
    };
    MyVector():elements(0),capacity(10){
        arr = new t[capacity];
    }
    MyVector(int init_size):elements(init_size), capacity(init_size){
        arr = new t[init_size];
    }
    MyVector(int init_size, int val):elements(init_size), capacity(init_size){
        arr = new t[init_size];
        for (int i = 0; i < init_size; ++i) {
            arr[i] = val;
        }
    }
    int size(){
        return elements;
    }
    bool empty(){
        return elements==0;
    }
    void erase(int index){
        assert(index >= 0 && index < elements);
        for (int i = index; i < elements - 1; ++i) {
            arr[i] = arr[i+1];
        }
        elements--;
    }
    void insert(int index, t val){
        assert(index >= 0 && index < elements);
        if (elements == capacity)
            expand();
        for (int i = elements; i > index; --i) {
            arr[i] = arr[i-1];
        }
        elements++;
    }
    void push_back(t val){
        if (elements == capacity)
            expand();
        arr[++elements] = val;
    }
    void pop_back(){
        assert(elements > 0);
        elements--;
    }
    t At(int index){
        assert(index >= 0 && index < elements);
        return arr[index];
    }
    t& operator[](int index){
        return arr[index];
    }
    Iterator begin(){
        return &arr[0];
    }
    Iterator end(){
        return &arr[elements];
    }
    ~MyVector(){
        delete[] arr;
    }
};


#endif //ARRAYLIST_MYVECTOR_H
