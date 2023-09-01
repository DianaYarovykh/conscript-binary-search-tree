#include "captain.h"
#include "iostream"
#include "string"
using namespace std;
//Реалізація класу капітана
Captain::Captain(const string& surname, const string& name, int rank, int age, int experience)
    : Conscript(surname, name, rank, age), experience(experience) {}

Captain::Captain() : Conscript("", "", 0, 0), experience(0) {}

void Captain::show() const {
    Conscript::show();
    cout << "Experience: " << this->experience << " years\n";
}

ostream& operator<<(ostream& os, const Captain& captain) {
    os << static_cast<const Conscript&>(captain) << captain.experience << endl;
    return os;
}

istream& operator>>(istream& is, Captain& data) {
    is >> static_cast<Conscript&>(data) >> data.experience;
    return is;
}
