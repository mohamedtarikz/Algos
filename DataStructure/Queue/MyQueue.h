#ifndef QUEUE_MYQUEUE_H
#define QUEUE_MYQUEUE_H

#include "assert.h"

template<typename t> class MyQueue {
    t* arr;
    int elements,capacity;
    int first,last;
    bool full(){
        return elements == capacity;
    }
    void expand(){
        capacity += 10;
        t* tmp = new t[capacity];
        int idx_original = first, idx_new = 0;
        while(idx_original != last){
            tmp[idx_new] = arr[idx_original];
            idx_new++;idx_original++;
            idx_original%=capacity;
        }
        tmp[idx_new] = arr[idx_original];
        delete[] arr;
        arr = tmp;
        first = 0;
        last = idx_new;
    }
public:
    MyQueue(){
        first = last = -1;
        elements = 0;
        capacity = 10;
        arr = new t[capacity];
    }
    t back(){
        assert(elements > 0);
        return arr[last];
    }
    t front(){
        assert(elements > 0);
        return arr[first];
    }
    void push(t x){
        if(elements == capacity)
            expand();
        last++;
        last%=capacity;
        arr[last] = x;
        if(first == -1)
            first = 0;
        elements++;
    }
    void pop(){
        assert(elements > 0);
        first++;
        first%=capacity;
        elements--;
        if(empty()){
            last = first = -1;
        }
    }
    int size(){
        return elements;
    }
    bool empty(){
        return elements == 0;
    }
};



#endif //QUEUE_MYQUEUE_H
