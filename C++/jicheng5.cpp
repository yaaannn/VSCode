#include<iostream>
using namespace std;
class Employee{
private:
    string name;
    int age;
public:
    Employee(string Name,int Age):name(Name),age(Age){}
    ~Employee(){}
    string getName(){return name;}
    int getAge(){return age;}
};
class Leader:virtual public Employee{
private:
    string zw;
    string bm;
public:
    Leader(string Name,int Age,string Zw,string Bm):Employee(Name,Age),zw(Zw),bm(Bm){}
    ~Leader(){}
    string getZw(){return zw;}
    string grtBm(){return bm;}
};
class Engineer:virtual public Employee{
private:
    string zc;
    string zy;
public:
    Engineer(string Name,int Age,string Zc,string Zy):Employee(Name,Age),zc(Zc),zy(Zy){}
    ~Engineer(){}
    string getZc(){return zc;}
    string getZy(){return zy;}
};
class ChairEngineer:public Leader,public Engineer{
private:
public:
    ChairEngineer(string Name,int Age,string Zw,string Bm,string Zc,string Zy):Employee(Name,Age),
    Leader(Name,Age,Zw,Bm),Engineer(Name,Age,Zc,Zy){}
    ~ChairEngineer(){}
};
int main()
{
    //Employee e1("张三",17);
    //cout<<e1.getAge()<<e1.getName();
    //Leader l1("张三",18,"经理","人力");
    //cout<<l1.getName()<<l1.getAge()<<l1.getZw()<<l1.grtBm()<<endl;
    ChairEngineer ce("张三",18,"经理","人力","教授","计科");
    
}