#include <iostream>
using namespace std;
class MyClock
{
private:
    int hour;
    int minute;
    int second;

public:
    MyClock(int Hour, int Minute, int Second) : hour(Hour), minute(Minute), second(Second) {}
    ~MyClock(){};
    void ShowTime()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
    MyClock(MyClock &M) : hour(M.hour), minute(M.minute), second(M.second) {}
    friend MyClock &operator++(MyClock &M);//前置++
    friend MyClock operator++(MyClock &M, int);//后置++
};
MyClock &operator++(MyClock &M) //前置++
{
    M.hour = 0;
    M.minute = 0;
    M.second = 1;
    return M;
}
MyClock operator++(MyClock &M, int)//后置++
{
    MyClock old = M;
    ++M;
    return old;
}
int main()
{
    MyClock myClock(23, 59, 59);
    myClock.ShowTime();
    (myClock++).ShowTime();
    (++myClock).ShowTime();
    return 0;
}