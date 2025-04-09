#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 500010;

int n;
ll s[N];

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        ll a = 1e15;
        int l = n / 2 + 1;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            s[i] = s[i - 1] + x;
            if (i >= l)
                a = min(a, s[i] - s[i - l]);
        }
        printf("%lld %lld\n", a, s[n] - a);
    }

    return 0;
}