#include<iostream>
using namespace std;
class Vehicle{
private:
    int wheels;
    int weight;
public:
    Vehicle(int Wheels,int Weight){
        wheels = Wheels;
        weight = Weight;
    }
    ~Vehicle(){}
    void dispaly(){
        cout<<"车轮"<<wheels<<endl;
        cout<<"重量"<<weight<<endl;
    }
};
class Car:private Vehicle{
private:
    int passenger_load;
public:
    Car(int Wheels,int Weight,int Passenger_load):Vehicle(Wheels,Weight){
        passenger_load=Passenger_load;
    }
    ~Car(){}
    void display1(){
        dispaly();
        cout<<"搭载人数"<<passenger_load<<endl;
    }
};
class Truck:private Vehicle{
private:
    int passenger_load;
    int payload;
public:
    Truck(int Wheels,int Weight,int Passenger_load,int Payload):Vehicle(Wheels,Weight){
        passenger_load=Passenger_load;
        payload=Payload;
    }
    ~Truck(){}
    void dispaly2(){
        dispaly();
        cout<<"载人数"<<passenger_load<<endl;
        cout<<"载重"<<payload<<endl;
    }
};
int main(){
    Car c1(4,200,5);
    c1.display1();
    Truck t1(5,30,3,500);
    t1.dispaly2();
    return 0;
}