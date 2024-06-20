#include <iostream>
#include "AVLTree.hpp"
using namespace std;

AVLNode::AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    // Implement destructor if needed
}

int AVLTree::height(AVLNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVLTree::balanceFactor(AVLNode* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

AVLNode* AVLTree::insert(AVLNode* node, int value) {
    if (node == nullptr) return new AVLNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

AVLNode* AVLTree::deleteNode(AVLNode* root, int value) {
    if (root == nullptr) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLNode* temp = (root->left != nullptr) ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + std::max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void AVLTree::remove(int value) {
    root = deleteNode(root, value);
}


void AVLTree::postOrderTraversal(Stack& stack, AVLNode* node) {
    if (node == nullptr) return;

    postOrderTraversal(stack, node->left);
    postOrderTraversal(stack, node->right);
    stack.push(node->data);
}

void AVLTree::postOrderTraversal(Stack& stack) {
    postOrderTraversal(stack, root);
}

void AVLTree::processAVLTrees() {
    int avlIndex = 1;

    while (root != nullptr) {
        Stack stack(500); // Başlangıç kapasitesini belirt
        postOrderTraversal(stack);
        
    }

    // Process remaining AVL trees
    int sum = 0;
    Stack stack(500); // Başlangıç kapasitesini belirt
    postOrderTraversal(stack);

    while (!stack.isEmpty()) {
        sum += stack.pop();
    }

    // Print the final result for the last AVL tree
    int ascii = sum % (90 - 65 + 1) + 65;
    std::cout << "Last Character: " << static_cast<char>(ascii) << endl<<"AVL Number: " << avlIndex << std::endl;
}