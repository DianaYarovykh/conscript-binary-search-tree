#ifndef _CONSCRIPT_H
#define _CONSCRIPT_H
#include "iostream"
#include "string"
using namespace std;
//Визначення абстрактного класу Військовозобов'язаного
class Conscript {
    static int currentId;
public:
    int getId() const; //Метод присвоювання кожному об'єкту ID
protected:
    int _id;
    string _surname;
    string _name;
    int _rank;
    int _age;
public:
    Conscript(); //Конструктор 
    Conscript(string surname, string name, int rank, int age); //Конструктор з параметрами

    const string& getSurname() const;
    void setSurname(const string& surname);
    const string& getName() const;
    void setName(const string& name);                        //Стандартні set i get методи
    int getRank() const;
    void setRank(int rank);
    int getAge() const;
    void setAge(int age);

    virtual void show()const;
    virtual ~Conscript() = 0; //Віртуальний деструктор

    friend ostream& operator<<(ostream& os, const Conscript& conscript); 
    friend istream& operator>>(istream& is, Conscript& data);                  // Оператори перевантаження вводу та виводу інформації
};

#endif //_CONSCRIPT_H