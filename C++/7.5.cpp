#include<iostream>
using namespace std;
class Employee{
private:
    string name;
    int age;
public:
    Employee(string Name,int Age){
        name=Name;
        age=Age;
    }
    ~Employee(){}

};

class Leader:virtual public Employee{
private:
    string zw;
    string bm;
public:
    Leader(string Name,int Age,string Zw,string Bm):Employee(Name,Age){
        zw=Zw;
        bm=Bm;
    }
    ~Leader(){}
};

class Engineer:virtual public Employee{
private:
    string zc;
    string zy;
public:
    Engineer(string Name,int Age,string Zc,string Zy):Employee(Name,Age){
        zc=Zc;
        zy=Zy;
    }
};

class ChairEngineer:public Leader,public Engineer{
    
}