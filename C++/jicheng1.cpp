#include<iostream>
using namespace std;
class A{
private:
    int a,b;
public:
    A(int x,int y);
    ~A();
    int getA();
    int getB();
};
A::A(int x,int y){
    a=x;
    b=y;
}
A::~A(){}
int A::getA(){return a;}
int A::getB(){return b;}

class B:A{
public:
    B(int x,int y):A(x,y){}
    int getA();
};
int B::getA(){return 2*A::getA();}
int main(){
    A a1(2,3);
    B b1(2,3);
    cout<<a1.getA()<<" "<<a1.getB()<<endl;
    cout<<b1.getA()<<" "<<a1.getB()<<endl;
    return 0;
}
