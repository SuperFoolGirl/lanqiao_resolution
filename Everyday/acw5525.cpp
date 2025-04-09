#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, s;
int q[N], v[N];
bool st[N];

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &q[i], &v[i]);

    int res = 0, cnt = 0, e = 1, d = 1; // e表示能量，d表示方向
    while (cnt < n * 26)                // 设置循环上限，超出上限认为陷入死循环
    {
        cnt++;
        if (q[s])
        {
            if (e >= v[s] && st[s] == false)
            {
                st[s] = true;
                res++;
            }
        }
        else
        {
            e += v[s];
            d = -d; // 反向
        }

        s += e * d;
        // 越界
        if (s < 1 || s > n)
            break;
    }
    printf("%d", res);
    return 0;
}