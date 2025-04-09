// 学会用max和min解不等式

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 200010;

int n;
int h[N], a[N], rk[N];

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
        {
            int t;
            scanf("%d", &t);
            rk[t + 1] = i; // 前面有t个更高的，排在t+1位
        }

        // 确定不等式解集的上下限
        int l = 0, r = 1e9;
        for (int i = 1; i <= n; i++)
        {
            int A = h[rk[i]] - h[rk[i + 1]];
            int B = a[rk[i + 1]] - a[rk[i]];

            if (B > 0) // 确定不等式右边界，取交集用min
                r = min(r, (int)ceil((double)A / B) - 1);
            else if (B < 0) // 确定不等式左边界，取交集用max
                l = max(l, (int)floor((double)A / B) + 1);
            else if (A <= 0) // 无解
            {
                r = -1;
                break;
            }
        }

        if (l > r) // 处理不合理区间，本题只要求输出左边界
            l = -1;
        printf("%d\n", l);
    }
    return 0;
}