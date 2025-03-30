#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

typedef long long ll;

int n;
int w[N], l[N], r[N];

int main()
{
    scanf("%d", &n);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        w[i] = x;
        if (++l[x] == 1)
            cnt++;
    }

    ll res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = w[i];
        r[x]++;
        if (--l[x] == 0)
            cnt--;
        if (r[x] == 2)
        {
            res += cnt;
            if (l[x] > 0)
                res--;
        }
    }
    printf("%lld", res);
    return 0;
}