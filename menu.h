#ifndef _MENU_H
#define _MENU_H
#include "binarySearchTree.h"
#include "conscript.h"
#include "cadet.h"
#include "captain.h"
//���������� ����� ����
class Menu {
public:
    static char PrintMenu();

    static void MockTreeSetup(BinarySearchTree* bst); //����� ������������ ��������� ����������

    static Cadet* CreateCadet();
    static Captain* CreateCaptain();
    static void Dialog(); //����� ������� ������ � ������������

};

#endif //_MENU_H