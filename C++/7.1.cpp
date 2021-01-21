#include<iostream>
using namespace std;
class A{
private:
    int a,b;
public:
    A(int a1,int b1){
        a=a1;
        b=b1;
    }
    ~A(){}
    int getA(){
        return a;
    }
    int getB(){
        return b;
    }
};
class B:A{
public:
    B(int a1,int b1):A(a1,b1){}
    int getA(){
        return 2*A::getA();
    }
};
int main()
{
    A a1(2,3);
    cout<<a1.getA()<<" "<<a1.getB()<<endl;
    B b1(2,3);
    cout<<b1.getA()<<" "<<a1.getB()<<endl;
    
}