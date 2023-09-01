#include "cadet.h"
#include "iostream"
#include "string"
#include "conscript.h"
using namespace std;
//Реалізація класу курсанта
void Cadet::show() const {
    Conscript::show();
    cout << "Subordinate: " << _subordinate << endl;
}

Cadet::Cadet(const string& surname, const string& name, int rank, int age, string subordinate)
    : Conscript(surname, name, rank, age), _subordinate(move(subordinate)) {}

const string& Cadet::getSubordinate() const {
    return _subordinate;
}

void Cadet::setSubordinate(const string& subordinate) {
    _subordinate = subordinate;
}

Cadet::Cadet() : Conscript("", "", 0, 0), _subordinate("") {}

ostream& operator<<(ostream& os, const Cadet& cadet) {
    os << static_cast<const Conscript&>(cadet) << cadet._subordinate << endl;
    return os;
}

istream& operator>>(istream& is, Cadet& data) {
    is >> static_cast<Conscript&>(data) >> data._subordinate;
    return is;
}
