#include <iostream>
using namespace std;

int myfact(int n)
{
    if (n == 1)
        return 1;
    return myfact(n - 2) + n;
}

int main()
{
    int sum=myfact(99);
    printf("你好%d",sum);
    return 0;
}