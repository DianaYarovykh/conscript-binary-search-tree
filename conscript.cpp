#include "conscript.h"
using namespace std;
//Реалізація абстрактного класу
int Conscript::currentId;
void Conscript::show() const 
{
    cout << "ID: " << getId() << std::endl;
    cout << "Surname: " << getSurname() << std::endl;
    cout << "Name: " << getName() << std::endl;
    cout << "Rank: " << getRank() << std::endl;
    cout << "Age: " << getAge() << std::endl;
}

Conscript::Conscript() : _id(currentId++), _surname(""), _name(""), _rank(0), _age(0) {}

const string& Conscript::getSurname() const 
{
    return _surname;
}

void Conscript::setSurname(const string& surname) {
    _surname = surname;
}

const string& Conscript::getName() const {
    return _name;
}

void Conscript::setName(const string& name) {
    _name = name;
}

int Conscript::getRank() const {
    return _rank;
}

void Conscript::setRank(int rank) {
    _rank = rank;
}

int Conscript::getAge() const {
    return _age;
}

void Conscript::setAge(int age) {
    _age = age;
}

Conscript::Conscript(string surname, string name, int rank, int age) : _id(currentId++), _surname(move(surname)),
    _name(std::move(name)),
    _rank(rank),
    _age(age) {}

int Conscript::getId() const {
    return _id;
}

ostream& operator<<(ostream& os, const Conscript& conscript) {
    os << conscript._id << endl << conscript._surname << endl << conscript._name << endl
        << conscript._rank << endl << conscript._age << endl;
    return os;
}

istream& operator>>(istream& is, Conscript& data) {
    is >> data._id >> data._surname >> data._name >> data._rank >> data._age;
    return is;
}

Conscript::~Conscript() = default;