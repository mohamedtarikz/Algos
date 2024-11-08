//
// Created by moham on 11/8/2024.
//

#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

template<typename T>
struct Node{
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    int height;

    Node(T val = 0, Node<T>* parent = nullptr){
        this->val = val;
        left = nullptr;
        right = nullptr;
        this->parent = parent;
        height = 0;
    }
};

#endif //AVL_TREE_NODE_H
