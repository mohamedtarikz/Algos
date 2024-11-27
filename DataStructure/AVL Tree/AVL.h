#ifndef AVL_TREE_AVL_H
#define AVL_TREE_AVL_H

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <memory>
#include "Node.h"

enum class Order { inOrder, postOrder, preOrder };

template<typename T>
class AVL {
    std::unique_ptr<Node<T>> root;
    int count;

    int calcHeightDiff(Node<T>* node) {
        int hLeft = (node->left ? node->left->height : -1);
        int hRight = (node->right ? node->right->height : -1);
        return hLeft - hRight;
    }

    void updateHeight(Node<T>* node) {
        node->height = 1 + std::max((node->left ? node->left->height : -1), (node->right ? node->right->height : -1));
    }

    void rotateLeft(Node<T>*& node) {
        auto child = std::move(node->right);
        node->right = std::move(child->left);
        if (node->right) node->right->parent = node;
        child->left = std::move(node);
        child->left->parent = child.get();
        node = std::move(child);
        updateHeight(node->left.get());
        updateHeight(node->get());
    }

    void rotateRight(Node<T>*& node) {
        auto child = std::move(node->left);
        node->left = std::move(child->right);
        if (node->left) node->left->parent = node;
        child->right = std::move(node);
        child->right->parent = child.get();
        node = std::move(child);
        updateHeight(node->right.get());
        updateHeight(node->get());
    }

    void balance(Node<T>*& node) {
        updateHeight(node);
        int balanceFactor = calcHeightDiff(node);
        if (balanceFactor == 2) {
            if (calcHeightDiff(node->left.get()) < 0) {
                rotateLeft(node->left);
            }
            rotateRight(node);
        } else if (balanceFactor == -2) {
            if (calcHeightDiff(node->right.get()) > 0) {
                rotateRight(node->right);
            }
            rotateLeft(node);
        }
    }

    void insertP(std::unique_ptr<Node<T>>& node, T val, Node<T>* parent) {
        if (!node) {
            node = std::make_unique<Node<T>>(val, parent);
            count++;
        } else if (val < node->val) {
            insert(reinterpret_cast<std::unique_ptr<Node<int>> &>(node->left), val, node.get());
        } else if (val > node->val) {
            insert(node->right, val, node.get());
        } else {
            throw std::invalid_argument("duplicates are not allowed, value already exists");
        }
        balance(node);
    }

    void eraseP(std::unique_ptr<Node<T>>& node, T val) {
        if (!node) {
            throw std::invalid_argument("value not present");
        } else if (val < node->val) {
            erase(node->left, val);
        } else if (val > node->val) {
            erase(node->right, val);
        } else {
            if (!node->left) {
                node = std::move(node->right);
            } else if (!node->right) {
                node = std::move(node->left);
            } else {
                auto minNode = findMin(node->right.get());
                node->val = minNode->val;
                erase(node->right, minNode->val);
            }
            count--;
        }
        if (node) balance(node);
    }

    Node<T>* findMin(Node<T>* node) const {
        while (node->left) node = node->left.get();
        return node;
    }

    void inOrder(Node<T>* node) const {
        if (!node) return;
        inOrder(node->left.get());
        std::cout << node->val << " ";
        inOrder(node->right.get());
    }

    void preOrder(Node<T>* node) const {
        if (!node) return;
        std::cout << node->val << " ";
        preOrder(node->left.get());
        preOrder(node->right.get());
    }

    void postOrder(Node<T>* node) const {
        if (!node) return;
        postOrder(node->left.get());
        postOrder(node->right.get());
        std::cout << node->val << " ";
    }

public:
    AVL() : root(nullptr), count(0) {}

    int size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }

    Node<T>* search(T val) const {
        auto temp = root.get();
        while (temp) {
            if (temp->val == val) return temp;
            temp = (val < temp->val) ? temp->left.get() : temp->right.get();
        }
        return nullptr;
    }

    void insert(T val, int i, Node<int> *pNode) {
        insertP(root, val, nullptr);
    }

    void erase(T val) {
        eraseP(root, val);
    }

    void print(Order order = Order::inOrder) const {
        if (order == Order::inOrder) {
            inOrder(root.get());
        } else if (order == Order::postOrder) {
            postOrder(root.get());
        } else {
            preOrder(root.get());
        }
        std::cout << std::endl;
    }
};

#endif // AVL_TREE_AVL_H