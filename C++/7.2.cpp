#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    string sex;
    int age;

public:
    Person(string Name, string Sex, int Age)
    {
        name = Name;
        //this->name=name;
        sex = Sex;
        age = Age;
    }
    void display()
    {
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "年龄：" << age << endl;
    }
};

class Teacher : public Person
{
private:
    int num1;
    string zc;
    int gz;

public:
    Teacher(string Name, string Sex, int Age, int Num1, string Zc, int Gz) : Person(Name, Sex, Age), num1(Num1), zc(Zc), gz(Gz) {}
    void display1()
    {
        cout << "教师类：" << endl;
        display();
        cout << "工号：" << num1 << endl;
        cout << "职称：" << zc << endl;
        cout << "工资：" << gz << endl;
    }
};

class Student : public Person
{
private:
    int num2;
    string bj;
    string zy;
    int socre;

public:
    Student(string Name, string Sex, int Age, int Num2, string Bj, string Zy, int Socre) : Person(Name, Sex, Age)
    {
        num2 = Num2;
        bj = Bj;
        zy = Zy;
        socre = Socre;
    }
    void display2()
    {
        cout << "学生类：" << endl;
        display();
        cout << "学号：" << num2 << endl;
        cout << "班级：" << bj << endl;
        cout << "专业：" << zy << endl;
        cout << "成绩：" << socre << endl;
    }
};
int main()
{
    Teacher t1("张三", "男", 20, 1001, "副教授", 3000);
    Student s1("李四", "男", 18, 110, "三年二班", "软件工程", 999);
    t1.display1();
    s1.display2();
}