#include <iostream>
using namespace std;
int main()
{
    int i, j, b;
    for (i = 1; i < 200; i++)
    {
        b = 1;
        for (j = 2; j <= i / 2; j++)
            if (i % j == 0)
            {
                b = 0;
                break;
            }
        if (b)
            cout << i << " ";
    }
    cout << endl;
}