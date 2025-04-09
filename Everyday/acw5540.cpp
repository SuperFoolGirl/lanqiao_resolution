// 唯一会做的二分
// t[i] + s < c[i]，为了二分移项处理，s < c[i] - t[i]

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, q;
int c[N], t[N];
int v, s;

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]), c[i] -= t[i];

    sort(c, c + n);

    while (q--)
    {
        scanf("%d%d", &v, &s);
        // 下标确定
        // 右边为蓝色
        int l = -1, r = n;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (c[mid] > s)
                r = mid;
            else
                l = mid;
        }
        // 取r
        if (n - r >= v)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}