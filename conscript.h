#ifndef _CONSCRIPT_H
#define _CONSCRIPT_H
#include "iostream"
#include "string"
using namespace std;
//���������� ������������ ����� ³������������'�������
class Conscript {
    static int currentId;
public:
    int getId() const; //����� ������������ ������� ��'���� ID
protected:
    int _id;
    string _surname;
    string _name;
    int _rank;
    int _age;
public:
    Conscript(); //����������� 
    Conscript(string surname, string name, int rank, int age); //����������� � �����������

    const string& getSurname() const;
    void setSurname(const string& surname);
    const string& getName() const;
    void setName(const string& name);                        //��������� set i get ������
    int getRank() const;
    void setRank(int rank);
    int getAge() const;
    void setAge(int age);

    virtual void show()const;
    virtual ~Conscript() = 0; //³��������� ����������

    friend ostream& operator<<(ostream& os, const Conscript& conscript); 
    friend istream& operator>>(istream& is, Conscript& data);                  // ��������� �������������� ����� �� ������ ����������
};

#endif //_CONSCRIPT_H