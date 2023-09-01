#ifndef _CADET_H
#define _CADET_H
#include "iostream"
#include "string"
#include "conscript.h"
using namespace std;
//Визначення класу військового курсанта
class Cadet : public Conscript { 
private:
    string _subordinate;
public:
    const string& getSubordinate() const;

    void setSubordinate(const string& subordinate);

    Cadet(const string& surname, const string& name, int rank, int age, string subordinate);

    Cadet();

    void show() const;

    friend ostream& operator<<(ostream& os, const Cadet& cadet);
    friend istream& operator>>(istream& is, Cadet& data);
    ~Cadet() = default;

};
#endif //_CADET_H
