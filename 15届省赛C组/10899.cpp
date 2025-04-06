#include <iostream>
using namespace std;
unsigned long long ntime, ftime, ansK, sumK = 1;

int main()
{
    char n, m;
    while (cin >> n >> m >> ntime)
    {
        if (n == m && ntime - ftime <= 1000)
            sumK++;
        else
        {
            if (sumK > ansK)
                ansK = sumK;
            sumK = 1;
        }
        ftime = ntime;
    }
    cout << ansK;
    return 0;
}