//
// Created by moham on 10/7/2024.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <cassert>
#include <stdexcept>
#include <iostream>

template<typename T>
struct Node{
    T val;
    Node<T> *left;
    Node<T> *right;

    Node(){
        val = NULL;
        left = right = nullptr;
    }
    Node(T val){
        this->val = val;
        left = right = nullptr;
    }
};

enum class Order{inOrder, postOrder, preOrder};

template<typename T>
class BST {
    Node<T>* root;
    int count;

    void in_Order(Node<T>* node){
        if(node == nullptr)
            return;
        in_Order(node->left);
        std::cout<<node->val<<" ";
        in_Order(node->right);
    }

    void pre_Order(Node<T>* node){
        if(node == nullptr)
            return;
        std::cout<<node->val<<" ";
        pre_Order(node->left);
        pre_Order(node->right);
    }

    void post_Order(Node<T>* node){
        if(node == nullptr)
            return;
        post_Order(node->left);
        post_Order(node->right);
        std::cout<<node->val<<" ";
    }

public:

    int traverse(Node<T>* node = nullptr, bool isFirst = true){
        if(isFirst){
            node = root;
        }
        if(node == nullptr){
            return 0;
        }
        int ret = traverse(node->left, false) + traverse(node->right, false);
        return ret + 1;
    }

    BST(){
        count = 0;
        root = nullptr;
    }

    int size(){
        return count;
    }

    bool empty(){
        return (count == 0);
    }

    Node<T>* find(T val){
        auto tmp = root;

        while(tmp != nullptr && tmp->val != val) {
            if (val > tmp->val) {
                tmp = tmp->right;
            }
            else{
                tmp = tmp->left;
            }
        }

        return tmp;
    }

    bool contains(T val){
        auto ans = find(val);
        return (ans != nullptr);
    }

    void insert(T val){
        if(contains(val)){
            throw std::invalid_argument("duplicates not allowed!");
        }
        count++;
        if(root == nullptr){
            root = new Node<T>(val);
            return;
        }
        auto tmp = root;
        while(true){
            if(val > tmp->val){
                if(tmp->right == nullptr){
                    tmp->right = new Node<T>(val);
                    return;
                }
                tmp = tmp->right;
            }
            else{
                if(tmp->left == nullptr){
                    tmp->left = new Node<T>(val);
                    return;
                }
                tmp = tmp->left;
            }
        }
    }

    void erase(T val){
        if(!contains(val)){
            throw std::invalid_argument("value not present!");
        }
        count--;
        if(root->val == val){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
            }
            else if(root->left == nullptr){
                auto tmpNode = root->right;
                delete root;
                root = tmpNode;
            }
            else if(root->right == nullptr){
                auto tmpNode = root->left;
                delete root;
                root = tmpNode;
            }
            else{
                auto tmpNode = root->right;
                T tmpVal;
                while(tmpNode->left != nullptr){
                    tmpNode = tmpNode->left;
                }
                tmpVal = tmpNode->val;
                erase(tmpVal);
                root->val = tmpVal;
            }
            return;
        }
        auto tmp = root;
        while(true){
            if(tmp->right != nullptr && val > tmp->val){
                if(tmp->right->val == val){
                    break;
                }
                tmp = tmp->right;
            }
            else{
                if(tmp->left->val == val){
                    break;
                }
                tmp = tmp->left;
            }
        }
        if(tmp->left != nullptr && tmp->left->val == val){
            if(tmp->left->left == nullptr && tmp->left->right == nullptr){
                delete tmp->left;
                tmp->left = nullptr;
            }
            else if(tmp->left->left == nullptr){
                auto tmpNode = tmp->left->right;
                delete tmp->left;
                tmp->left = tmpNode;
            }
            else if(tmp->left->right == nullptr){
                auto tmpNode = tmp->left->left;
                delete tmp->left;
                tmp->left = tmpNode;
            }
            else{
                auto tmpNode = tmp->left->right;
                T tmpVal;
                while(tmpNode->left != nullptr){
                    tmpNode = tmpNode->left;
                }
                tmpVal = tmpNode->val;
                erase(tmpVal);
                tmp->left->val = tmpVal;
            }
        }
        else{
            if(tmp->right->left == nullptr && tmp->right->right == nullptr){
                delete tmp->right;
                tmp->right = nullptr;
            }
            else if(tmp->right->left == nullptr){
                auto tmpNode = tmp->right->right;
                delete tmp->right;
                tmp->right = tmpNode;
            }
            else if(tmp->right->right == nullptr){
                auto tmpNode = tmp->right->left;
                delete tmp->right;
                tmp->right = tmpNode;
            }
            else{
                auto tmpNode = tmp->right->right;
                T tmpVal;
                while(tmpNode->left != nullptr){
                    tmpNode = tmpNode->left;
                }
                tmpVal = tmpNode->val;
                erase(tmpVal);
                tmp->right->val = tmpVal;
            }
        }
    }

    void print(Order order = Order::inOrder){
        if(order == Order::inOrder){
            in_Order(root);
        }
        else if(order == Order::postOrder){
            post_Order(root);
        }
        else{
            pre_Order(root);
        }
        std::cout<<std::endl;
    }
};


#endif //BST_BST_H
