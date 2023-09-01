#include "menu.h"
using namespace std;
//Реалізація меню
char Menu::PrintMenu() {
    int variant;
    cout << endl;
    cout << "----------------MENU----------------" << endl;
    cout << "1. Add new cadet" << endl;
    cout << "2. Add new captain" << endl;
    cout << "3. Print all tree" << endl;
    cout << "4. Print captain subordinates by rank" << endl;
    cout << "5. Use mock data" << endl;
    cout << "6. Load from file" << endl;
    cout << "7. Load in file" << endl;
    cout << "8. Clean binary tree" << endl;
    cout << "9. Exit program" << endl;
    cout << "Choose please: ";
    cin >> variant;
    cout << "\r" << endl;
    return variant;
}
/*Для полегшення роботи з деревом я створила функцію, що містить вбудовану інформацію для кожного об'єкта.
Оскільки для перевірки функціонування пошуку по дереву недостатньо 1-2 об'єктів*/
void Menu::MockTreeSetup(BinarySearchTree* bst) {
    bst->Insert(new Captain("Sydorov", "Sidr", 15, 30, 4));
    bst->Insert(new Cadet("Ivanov", "Ivan", 8, 22, "2_polk"));
    bst->Insert(new Captain("Petrov", "Petro", 45, 55, 25));
    bst->Insert(new Cadet("Nykolayv", "Nykolay", 1, 21, "2_polk"));
    bst->Insert(new Cadet("Aloxin", "Alixey", 10, 20, "2_polk"));
    bst->Insert(new Cadet("Alexandrov", "Alexandr", 30, 35, "1_polk"));
    bst->Insert(new Cadet("Nikitin", "Nikita", 55, 42, "1_polk"));
    bst->Insert(new Captain("Pavlov", "Pavlo", 31, 43, 14));
    bst->Insert(new Cadet("Valerych", "Valeriy", 13, 28, "3_polk"));
    bst->Insert(new Cadet("Illich", "Illiya", 24, 29, "3_polk"));
    cout << "Information uploaded successfully!" << endl;
}

Cadet* Menu::CreateCadet() {
    string firstName;
    string lastName;
    int rank;
    int age;
    string subordinate;
    cout << "First Name:" << endl;
    cin >> firstName;
    cout << "Last Name:" << endl;
    cin >> lastName;
    cout << "Rank:" << endl;
    cin >> rank;
    cout << "Age:" << endl;
    cin >> age;
    cout << "Subordinate:" << endl;
    cin >> subordinate;
    return new Cadet(lastName, firstName, rank, age, subordinate);
}

Captain* Menu::CreateCaptain() {
    string firstName;
    string lastName;
    int rank;
    int age;
    int experience;
    cout << "First Name:" << endl;
    cin >> firstName;
    cout << "Last Name:" << endl;
    cin >> lastName;
    cout << "Rank:" << endl;
    cin >> rank;
    cout << "Age:" << endl;
    cin >> age;
    cout << "Years of experience:" << endl;
    cin >> experience;
    return new Captain(lastName, firstName, rank, age, experience);
}

void Menu::Dialog() {
    int variant = 0;
    auto* tree = new BinarySearchTree();
    do {
        variant = PrintMenu();
        switch (variant) 
        {
        case 1:
            tree->Insert(CreateCadet());
            break;
        case 2:
            tree->Insert(CreateCaptain());
            break;
        case 3:
            tree->PrintTree();
            break;
        case 4:
            int rank;
            cout << "Input captain rank: ";
            cin >> rank;
            tree->PrintChildrenByRank(rank);
            break;
        case 5:
            MockTreeSetup(tree);
            break;
        case 6:
            tree->LoadFromFile();
            break;
        case 7:
            tree->LoadIntoFile();
            break;
        case 8:
            delete tree;
            tree = new BinarySearchTree();
            cout << "Tree is clean!" << endl;
            break;
        case 9:
            delete tree;
            cout << "Thank you!" << endl;
            system("pause");
            break;
        default:
            cout << "Try again!" << endl;
            variant = PrintMenu();
            break;
        }
    } while (variant != 9);
}