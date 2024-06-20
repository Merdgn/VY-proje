#include <iostream>
#include <fstream>
#include "AVLTree.hpp"
#include "Stack.hpp"
#include <sstream>
#include <cstdlib> 
#include <iomanip>

using namespace std;
void clearScreen() {
#ifdef _WIN32
    // For Windows
    system("cls");
#endif
}

int main() {
    ifstream inputFile("veri.txt");

    if (!inputFile.is_open()) {
        
        return 1;
    }

    Stack charStack(500); // Karakterleri tutmak için stack

    int avlIndex = 1;

    while (inputFile.good()) {
        AVLTree* avlTree = new AVLTree();
        string line;
        getline(inputFile, line);

        istringstream iss(line);
        int number;

        while (iss >> number) {
            avlTree->insert(number);
        }

        avlTree->postOrderTraversal(charStack);

        // Yazdırılan karakterleri arasına boşluk bırakarak ekrana yazdır
        while (!charStack.isEmpty()) {
            char currentChar = static_cast<char>(charStack.pop());
            cout << currentChar;
            if (!charStack.isEmpty()) {
                cout << " ";
            }
        }

        // Ekrandaki karakterleri temizle
        system("cls");

        delete avlTree;

        // Bekleme süresi, isteğe bağlı olarak arttırılabilir
        // Bu süre zarfında ekrandaki karakterler görülebilir
        // sleep(milliseconds); // Örnek: std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    // Print the final result for the last AVL tree
    int sum = 0;
    AVLTree* lastAVLTree = new AVLTree();
    lastAVLTree->postOrderTraversal(charStack);

    // Yazdırılan karakterleri arasına boşluk bırakarak ekrana yazdır
    while (!charStack.isEmpty()) {
        char currentChar = static_cast<char>(charStack.pop());
        cout << currentChar;
        if (!charStack.isEmpty()) {
            cout << "";
        }
    }

    // Calculate and print ASCII value for the last AVL tree
    int ascii = sum % (90 - 65 + 1) + 65;
    cout << "SON KARAKTER: " << static_cast<char>(ascii) << endl
         << "AVL NO: " << avlIndex << endl;

    // Free memory for the last AVL tree
    delete lastAVLTree;

    return 0;
}
