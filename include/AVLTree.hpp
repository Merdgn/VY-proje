#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "Stack.hpp"

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value);
};

class AVLTree {
private:
    AVLNode* root;

    AVLNode* insert(AVLNode* node, int value);
    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* minValueNode(AVLNode* node);
    AVLNode* deleteNode(AVLNode* root, int value);

public:
    AVLTree();
    ~AVLTree();

    void insert(int value);
    void remove(int value);
    void postOrderTraversal(Stack& stack, AVLNode* node); 
    void postOrderTraversal(Stack& stack); // Güncellendi
    void processAVLTrees(); // Güncellendi
};

#endif