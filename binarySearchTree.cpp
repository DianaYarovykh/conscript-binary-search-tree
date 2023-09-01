#include <fstream>
#include "binarySearchTree.h"
#include "captain.h"
#include "cadet.h"
using namespace std;
//Реалізація бінарного дерева пошуку
Node::~Node() {
    delete data;
}

Node::Node(Conscript* data) {
    this->data = data;
}

Node::Node() = default;

Node* BinarySearchTree::RecursiveSearch(Node* root, int rank) {
    if (root == nullptr || root->data->getRank() == rank)
        return root;
    if (root->data->getRank() < rank)
        return RecursiveSearch(root->right, rank);
    return RecursiveSearch(root->left, rank);
}
Conscript* BinarySearchTree::Search(int rank) //Пошук
{
    auto* node = RecursiveSearch(root, rank);
    if (node == nullptr)
        return nullptr;
    return node->data;
}
void BinarySearchTree::Insert(Conscript* data) //Заповнення контейнера
{
    RecursiveInsert(root, data);
}
void BinarySearchTree::RecursiveInsert(Node*& node, Conscript* data) {
    if (node == nullptr) {
        node = new Node(data);
    }
    else {
        if (data->getRank() < node->data->getRank())
            RecursiveInsert(node->left, data);
        else
            RecursiveInsert(node->right, data);
    }
}

void BinarySearchTree::PrintInorder(Node* node) //Функція, що виводить інформацію, що міститься у дереві на екран
{
    if (node == nullptr)
        return;
    PrintInorder(node->left);
    node->data->show();
    cout << endl;
    PrintInorder(node->right);
}

void BinarySearchTree::PrintTree() {
    PrintInorder(root);
}
void BinarySearchTree::PrintInorderCadet(Node* node)  //Функція що виводить лише кадетів
{
    if (node == nullptr)
        return;
    PrintInorderCadet(node->left);
    if (dynamic_cast<Cadet*>(node->data) != nullptr)
    {
        node->data->show();
        cout << endl;
    }
    PrintInorderCadet(node->right);
}
void BinarySearchTree::PrintChildrenByRank(int rank) {
    auto* node = RecursiveSearch(root, rank);
    if (dynamic_cast<Captain*>(node->data) != nullptr)        //Перевірка чи відповідає заданий ранг капітану
    {
        PrintInorderCadet(node);
        return;
    }
    cout << "This is not captain." << endl;
}

BinarySearchTree::~BinarySearchTree() //Деструктор викликає функцію для видалення даних з дерева
{
    CleanTree(root);
}
void BinarySearchTree::CleanTree(Node* node) {
    if (node == nullptr) return;
    CleanTree(node->left);
    CleanTree(node->right);

    delete node;
}

void BinarySearchTree::LoadFromFile() //Функція зчитування з файлу
{
    string flName;
    cout << "File name:" << endl;
    cin >> flName;
    ifstream in(flName);
    try                        //Обробка вийнятків
    {
        if (!in.is_open())
        {
            throw exception();
        }
        Cadet* cadetObj;
        Captain* captainObj;
        int info;
        in >> info;
        while (!in.eof())
        {
            if (info == 1)
            {
                cadetObj = new Cadet();
                in >> (*cadetObj);
                Insert(cadetObj);
            }
            if (info == 2)
            {
                captainObj = new Captain();
                in >> (*captainObj);
                Insert(captainObj);
            }
            in >> info;
        }
        cout << "Information loaded from file" << endl;
    }
    catch (const std::exception&e)
    {
        cout << "Error of open..." << endl;
    }
    in.close();
};

void BinarySearchTree::LoadIntoFile() //Функція запису інформації у файл
{
    if (root == nullptr)
    {
        cout << "There is no data in tree" << endl;
        return;
    }
    ofstream out("Output.txt");
    if (!out.is_open())
    {
        cout << "Error of open..." << endl;
        return;
    }
    LoadIntoFileRecursively(root, out);
    out.close();
}
void BinarySearchTree::LoadIntoFileRecursively(Node* nextNode, ofstream& out) {
    if (!nextNode)
       return;
    else
    {
        if (dynamic_cast<Cadet*>(nextNode->data) != nullptr)
        {
            out << 1 << '\n';
            out << *((Cadet*)(nextNode->data));
        }
        if (dynamic_cast<Captain*>(nextNode->data) != nullptr)
        {
            out << 2 << '\n';
            out << *((Captain*)(nextNode->data));
        }
        cout << "Information saved in file" << endl;
        LoadIntoFileRecursively(nextNode->left, out);
        LoadIntoFileRecursively(nextNode->right, out);
    }
}