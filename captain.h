#ifndef _CAPTAIN_H
#define _CAPTAIN_H
#include <ostream>
#include "conscript.h"
#include "istream"
#include "string"
using namespace std;

//Визначення класу капітана
class Captain : public Conscript {
private:
    int experience;
public:
    Captain();
    Captain(const string& surname, const string& name, int rank, int age, int experience);

    friend ostream& operator<<(ostream& os, const Captain& captain);
    friend istream& operator>>(istream& is, Captain& data);
public:
    void show() const override;
    ~Captain() override = default;
};
#endif //_CAPTAIN_H