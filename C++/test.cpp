#include <iostream>
#include <cstring>
using namespace std;
class person
{
public:
    person(char *a, char *b, int s)
    {
        name = a;
        sex = b;
        score = s;
    }
    void display()
    {
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "年龄：" << score << endl;
    }
private:
    char *name;
    char *sex;
    int score;
};

int main()
{
    person p1("张三","男",18);
    p1.display();
    
}