#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H
#include "conscript.h"
//Структура для реалізації бінарного дерева
struct Node {
public:
    struct Node* left = nullptr;      
    struct Node* right = nullptr;
    Node();
    Node(Conscript* data);
    Conscript* data = nullptr;
    ~Node();
};
//Визначення класу контейнера
class BinarySearchTree {
private:
    Node* root;  //Корінь дерева, що встановлюється першим і вже від нього йде розмежування
public:
    Node* RecursiveSearch(Node* root, int rank);
    void RecursiveInsert(Node*& node, Conscript* data);
    void PrintInorder(Node* node);
    void PrintInorderCadet(Node* node);
    void CleanTree(Node* node);
    void PrintTree();
    void Insert(Conscript* data);
    void PrintChildrenByRank(int rank);
    Conscript* Search(int rank);
    void LoadFromFile();
    void LoadIntoFile();
    void LoadIntoFileRecursively(Node* nextNode, ofstream& out);
    virtual ~BinarySearchTree();
};
#endif //_BINARYSEARCHTREE_H