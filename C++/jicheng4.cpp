#include<iostream>
using namespace std;
class Vehicle{
private:
    int wheels;
    int weight;
public:
    Vehicle(int wheels,int weight){
        this->wheels=wheels;
        this->weight=weight;
    }
    void display(){
        cout<<wheels<<" "<<weight<<" ";
    }
};
class Car:private Vehicle{
private:
    int passenger_load;
public:
    Car(int wheels,int weight,int passenger_load):Vehicle(wheels,weight){
        this->passenger_load=passenger_load;
    }
    void dispaly1(){
        display();
        cout<<passenger_load<<endl;
    }
};
class Truck:private Vehicle{
private:
    int passenger_load;
    int payload;
public:
    Truck(int wheels,int weight,int passenger_load,int payload):Vehicle(wheels,weight){
        this->passenger_load=passenger_load;
        this->payload=payload;
    }
    void display2(){
        display();
        cout<<passenger_load<<" "<<payload;
    }
};
int main(){
    Car c(2,200,30);
    Truck t(2,200,20,500);
    c.dispaly1();
    t.display2();
}
