//
// Created by moham on 9/8/2024.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"
#include "Operation.h"
#include <cassert>
#include <stack>
using namespace std;

template<typename T>
class LinkedList {
    int count;
    Node<T>* head;
    Node<T>* tail;

    stack<Operation*> undo_stack;

    Node<T>* getNode(int index){
        assert(index < count);
        auto tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->next;
        }
        return tmp;
    }

public:
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
        undo_stack.push(new Append<T>);
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
        undo_stack.push(new Insert<T>(index));
    }

    void erase(int index){
        assert(index >= 0 && index < count);
        T val;
        if(index) {
            auto tmp = getNode(index - 1);
            val = tmp->next->value;
            auto nextNode = tmp->next->next;
            delete tmp->next;
            tmp->next = nextNode;
        }
        else{
            val = head->value;
            auto tmp = head->next;
            delete head;
            head = tmp;
        }
        count--;
        undo_stack.push(new Erase<T>(index,val));
    }

    void sort(bool(*comp)(T a, T b) = [](T a, T b){return a < b;}){
        vector<T> val;
        auto itr = head;
        for(int i = 0; i < count; i++){
            val.push_back(itr->value);
            itr = itr->next;
        }
        undo_stack.push(new Sort<T>(val));
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

    void undo(){
        assert(!undo_stack.empty());

        if(undo_stack.top()->op == SORT){
            auto op = dynamic_cast<Sort<T>*>(undo_stack.top());
            auto vec = op->val;
            auto itr = head;
            for(int i = 0; i < count; i++){
                itr->value = vec[i];
                itr = itr->next;
            }
            delete op;
        }
        else if(undo_stack.top()->op == APPEND){
            erase(count - 1);
            undo_stack.pop();
        }
        else if(undo_stack.top()->op == ERASE){
            auto op = dynamic_cast<Erase<T>*>(undo_stack.top());
            insert(op->index,op->val);
            delete op;
            undo_stack.pop();
        }
        else{
            auto op = dynamic_cast<Insert<T>*>(undo_stack.top());
            erase(op->index);
            delete op;
            undo_stack.pop();
        }
        delete undo_stack.top();
        undo_stack.pop();
    }

    T& operator[](int index){
        assert(index >= 0 && index < count);

        auto tmp = getNode(index);
        return tmp->value;
    }

    int size(){
        return count;
    }
};

#endif //LINKEDLIST_LINKEDLIST_H
