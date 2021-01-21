#include <iostream>
#include <cstdio>
using namespace std;
int dunno(int a)
{
    int value;
    if (a == 0)
        value = 3;
    else
        value = dunno(a - 1) + 5;
    return value;
}
int main()
{
    int a = dunno(3);
    printf("%d", a);
    return 0;
}
