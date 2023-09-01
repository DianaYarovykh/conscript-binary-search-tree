#ifndef _MENU_H
#define _MENU_H
#include "binarySearchTree.h"
#include "conscript.h"
#include "cadet.h"
#include "captain.h"
//Визначення класу меню
class Menu {
public:
    static char PrintMenu();

    static void MockTreeSetup(BinarySearchTree* bst); //Метод використання вбудованої інформації

    static Cadet* CreateCadet();
    static Captain* CreateCaptain();
    static void Dialog(); //Метод запуску діалогу з користувачем

};

#endif //_MENU_H