//
// Created by moham on 9/27/2024.
//

#ifndef LINKEDLIST_OPERATION_H
#define LINKEDLIST_OPERATION_H

#include <vector>

enum operation{APPEND, INSERT, ERASE, SORT};

class Operation {
    virtual void none(){}
public:
    operation op;
    explicit Operation(operation assign_operation) : op{assign_operation}{}
};

template<typename T>
class Append: public Operation{
public:
    explicit Append() : Operation(APPEND){}
};

template<typename T>
class Insert: public Operation{
public:
    int index;
    explicit Insert(int assign_index) : Operation(INSERT), index{assign_index}{}
};

template<typename T>
class Erase: public Operation{
public:
    T val;
    int index;
    explicit Erase(int assign_index, T assign_val) : Operation(ERASE), val{assign_val}, index{assign_index}{}
};

template<typename T>
class Sort: public Operation{
public:
    std::vector<T> val;
    explicit Sort(std::vector<T> assign_val) : Operation(SORT), val{assign_val}{}
};

#endif //LINKEDLIST_OPERATION_H
