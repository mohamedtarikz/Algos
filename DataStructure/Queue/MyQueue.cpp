//
// Created by moham on 8/19/2024.
//

#include "MyQueue.h"
#include <assert.h>

namespace mystl {
    template<typename t>
    MyQueue<t>::MyQueue() {
        f = b = -1;
        elements = 0;
        capacity = 10;
        a = new t[capacity];
    }

    template<typename t>
    bool MyQueue<t>::full() {
        return elements == capacity;
    }

    template<typename t>
    bool MyQueue<t>::empty() {
        return elements == 0;
    }

    template<typename t>
    void MyQueue<t>::push(t x) {
        if(elements == capacity)
            expand();
        b++;
        b%=capacity;
        a[b] = x;
        if(f == -1)
            f = 0;
        elements++;
    }

    template<typename t>
    void MyQueue<t>::pop() {
        assert(elements > 0);
        f++;
        f%=capacity;
        elements--;
        if(empty()){
            b = f = -1;
        }
    }

    template<typename t>
    t MyQueue<t>::back() {
        assert(elements > 0);
        return a[b];
    }

    template<typename t>
    t MyQueue<t>::front() {
        assert(elements > 0);
        return a[f];
    }

    template<typename t>
    void MyQueue<t>::expand() {
        capacity += 10;
        t* tmp = new t[capacity];
        int idx = f, i = 0;
        while(idx != b){
            tmp[i] = a[idx];
            i++;idx++;
            idx%=capacity;
        }
        delete[] a;
        a = tmp;
    }

    template<typename t>
    int MyQueue<t>::size() {
        return elements;
    }
} // mystl