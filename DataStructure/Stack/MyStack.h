//
// Created by moham on 8/10/2024.
//

#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H

#include <bits/stdc++.h>

namespace stl {

    template<typename type> class MyStack {
        int capacity;
        int elements;
        type* a;
        void expand(){
            capacity += 10;
            type* tmp = new type[capacity];
            for (int i = 0; i < elements; ++i) {
                tmp [i] = a[i];
            }
            delete[] a;
            a = tmp;
        }
    public:
        MyStack(){
            capacity = 10;
            elements = 0;
            a = new type[capacity];
        }
        void pop(){
            elements--;
        }
        type top(){
            assert(elements > 0);
            return a[elements - 1];
        }
        int len(){
            return elements;
        }
        void push(type x){
            if(elements == capacity){
                expand();
            }
            a[elements++] = x;
        }
        bool empty(){
            return (elements == 0);
        }
    };

} // stl

#endif //STACK_MYSTACK_H
