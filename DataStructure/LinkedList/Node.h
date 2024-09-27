//
// Created by moham on 9/8/2024.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

template<typename T>
struct Node {//Node for LinkedList
    T value;
    Node<T>* next;
    Node(T value){
        this->value = value;
        this->next = nullptr;
    }
    Node(){
        this->value = 0;
        this->next = nullptr;
    }
};


#endif //LINKEDLIST_NODE_H
