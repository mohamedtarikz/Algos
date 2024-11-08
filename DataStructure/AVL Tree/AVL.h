#ifndef AVL_TREE_AVL_H
#define AVL_TREE_AVL_H

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "Node.h"

enum class Order{inOrder, postOrder, preOrder};

template<typename T>
class AVL {
    Node<T>* root;
    int count;

    int calcHeightDiff(Node<T>* node){
        int hLeft = (node->left != nullptr ? node->left->height : -1);
        int hRight = (node->right != nullptr ? node->right->height : -1);
        return hLeft - hRight;
    }

    void rotateLeft(Node<T>* node){
        auto parent = node;
        auto child = node->right;

        node = node->right;
        node->parent->right = node->left;
        if(node->left) {
            node->left->parent = node->parent;
        }
        node->left = node->parent;
        auto temp = node->parent->parent;
        if(node->parent->parent)
            node->parent->parent->right = node;
        node->parent->parent = node;
        node->parent = temp;

        if(parent == root){
            root = child;
        }

        parent->height = 1 + std::max((parent->left != nullptr ? parent->left->height : -1), (parent->right != nullptr ? parent->right->height : -1));
        child->height = 1 + std::max((child->left != nullptr ? child->left->height : -1), (child->right != nullptr ? child->right->height : -1));
    }

    void rotateRight(Node<T>* node){
        auto parent = node;
        auto child = node->left;

        node = node->left;
        node->parent->left = node->right;
        if(node->right) {
            node->right->parent = node->parent;
        }
        node->right = node->parent;
        auto temp = node->parent->parent;
        if(node->parent->parent)
            node->parent->parent->left = node;
        node->parent->parent = node;
        node->parent = temp;

        if(parent == root){
            root = child;
        }

        parent->height = 1 + std::max((parent->left != nullptr ? parent->left->height : -1), (parent->right != nullptr ? parent->right->height : -1));
        child->height = 1 + std::max((child->left != nullptr ? child->left->height : -1), (child->right != nullptr ? child->right->height : -1));
    }

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
    AVL(){
        root = nullptr;
        count = 0;
    }

    int size(){
        return count;
    }

    bool empty(){
        return count == 0;
    }

    Node<T>* search(T val){
        auto temp = root;
        while(temp != nullptr){
            if(temp->val == val)
                return temp;
            if(val < temp->val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return nullptr;
    }

    void insert(T val){
        //Check for duplicate value
        if (search(val) != nullptr){
            throw std::invalid_argument("duplicates are not allowed, value already exists");
        }

        //Increment nodes counter
        count++;
        //If no nodes yet add the root
        if(root == nullptr){
            root = new Node<T>(val);
            return;
        }

        //Put new node
        auto temp = root;
        while(true){
            if(val > temp->val){
                temp->height = 1 + std::max(temp->height, (temp->right != nullptr ? temp->right->height + 1 : -1));
                if(temp->right == nullptr){
                    temp->right = new Node<T>(val, temp);
                    break;
                }
                temp = temp->right;
            }
            else{
                temp->height = 1 + std::max(temp->height, (temp->left != nullptr ? temp->left->height + 1 : -1));
                if(temp->left == nullptr){
                    temp->left = new Node<T>(val, temp);
                    break;
                }
                temp = temp->left;
            }
        }

        //Re-balance the tree
        while(temp != nullptr){
            int heightDiff = calcHeightDiff(temp);
            if(heightDiff == 2){
                if(calcHeightDiff(temp->left) >= 0){
                    rotateRight(temp);
                }
                else{
                    rotateLeft(temp->left);
                    rotateRight(temp);
                }
            }
            else if(heightDiff == -2){
                if(calcHeightDiff(temp->right) <= 0){
                    rotateLeft(temp);
                }
                else{
                    rotateRight(temp->right);
                    rotateLeft(temp);
                }
            }
            temp = temp->parent;
        }
    }

    void erase(T val){
        auto temp = search(val);
        if(temp == nullptr){
            throw std::invalid_argument("value not present");
        }

        count--;
        if(root->val == val){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
            }
            else if(root->right == nullptr){
                auto parent = root->left;
                delete root;
                parent->parent = nullptr;
                root = parent;
            }
            else if(root->left == nullptr){
                auto parent = root->right;
                delete root;
                parent->parent = nullptr;
                root = parent;
            }
            else{
                auto parent = root->right;
                T tmpVal;
                while(parent->left != nullptr){
                    parent = parent->left;
                }
                tmpVal = parent->val;
                erase(parent->val);
                root->val = tmpVal;
            }
        }
        else{
            auto parent = temp->parent;
            if(parent->left != nullptr && parent->left->val == val){
                if(parent->left->left == nullptr && parent->left->right == nullptr){
                    delete parent->left;
                    parent->left = nullptr;
                }
                else if(parent->left->left == nullptr){
                    parent->left->right->parent = parent;
                    auto child = parent->left->right;
                    delete parent->left;
                    parent->left = child;
                }
                else if(parent->left->right == nullptr){
                    parent->left->left->parent = parent;
                    auto child = parent->left->left;
                    delete parent->left;
                    parent->left = child;
                }
                else{
                    auto child = parent->left->right;
                    T tmpVal;
                    while(child->left != nullptr){
                        child = child->left;
                    }
                    tmpVal = child->val;
                    erase(tmpVal);
                    parent->left->val = tmpVal;
                }
            }
            else{
                if(parent->right->left == nullptr && parent->right->right == nullptr){
                    delete parent->right;
                    parent->right = nullptr;
                }
                else if(parent->right->left == nullptr){
                    parent->right->right->parent = parent;
                    auto child = parent->right->right;
                    delete parent->right;
                    parent->right = child;
                }
                else if(parent->right->right == nullptr){
                    parent->right->left->parent = parent;
                    auto child = parent->right->left;
                    delete parent->right;
                    parent->right = child;
                }
                else{
                    auto child = parent->right->right;
                    T tmpVal;
                    while(child->left != nullptr){
                        child = child->left;
                    }
                    tmpVal = child->val;
                    erase(tmpVal);
                    parent->right->val = tmpVal;
                }
            }
        }

        //Re-balance the tree
        while(temp != nullptr){
            int heightDiff = calcHeightDiff(temp);
            if(heightDiff == 2){
                if(calcHeightDiff(temp->left) >= 0){
                    rotateRight(temp);
                }
                else{
                    rotateLeft(temp->left);
                    rotateRight(temp);
                }
            }
            else if(heightDiff == -2){
                if(calcHeightDiff(temp->right) <= 0){
                    rotateLeft(temp);
                }
                else{
                    rotateRight(temp->right);
                    rotateLeft(temp);
                }
            }
            temp = temp->parent;
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


#endif //AVL_TREE_AVL_H
