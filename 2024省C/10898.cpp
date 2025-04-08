#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const ll max2 = 7385137888721;
const ll max1 = 10470245;

int main()
{
    for (ll i = max2;; i--)
    {
        ll tmp = sqrt(max2);
        int diff = max2 - tmp * tmp;
        if (diff == 0 || max1 >= diff)
        {
            printf("%lld", tmp * 2);
            return 0;
        }
    }
}