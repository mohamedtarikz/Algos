//
// Created by moham on 8/19/2024.
//

#ifndef QUEUE_MYQUEUE_H
#define QUEUE_MYQUEUE_H

namespace mystl {

    template<typename type> class MyQueue {
        type* a;
        int elements,capacity;
        int f,b;
        bool full();
        void expand();
    public:
        MyQueue();
        type back();
        type front();
        void push(type x);
        void pop();
        int size();
        bool empty();
    };

} // mystl

#endif //QUEUE_MYQUEUE_H
