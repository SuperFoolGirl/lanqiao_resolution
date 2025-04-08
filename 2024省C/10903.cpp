// 差分数组求前缀和可还原为原数组

// 1. 处理前缀和时没考虑优化，TLE
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 300010;

int n, m;
int a[N], l[N], r[N], res[N];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &l[i], &r[i]);
        a[l[i]]++;
        a[r[i] + 1]--; // 越界了不影响，反正遍历不到
    }

    for (int i = 1; i <= m; i++)
    {
        int ans = 0;
        memset(res, 0, sizeof res);
        a[l[i]]--;
        a[r[i] + 1]++;
        // 求前缀和
        for (int j = 1; j <= n; j++)
        {
            res[j] = res[j - 1] + a[j];
            if (res[j] == 0)
                ans++;
        }
        printf("%d\n", ans);

        // 还原差分数组
        a[l[i]]++;
        a[r[i] + 1]--;
    }
    return 0;
}



// 2. 优化
/*
我们发现如果撤销第 i 个操作会让第 x 种商品的库存量为 0 那么只有两种情况：
1.所有操作过后第 x 种商品的库存量为 0。
2.所有操作过后第 x 种商品的库存量为 1，并且 x 在第 i 个操作区间内。
*/
// 但说实话也并不是很懂。。

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 300010;

int n, m;
int a[N], l[N], r[N], res[N];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &l[i], &r[i]);
        a[l[i]]++;
        a[r[i] + 1]--; // 越界了不影响，反正遍历不到
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        // 直接先求前缀和
        a[i] += a[i - 1];
        // 统计库存量为 0 的商品数量
        if (a[i] == 0)
            sum++;
        // 计算所有操作后库存量为1的前缀和
        res[i] = res[i - 1] + (a[i] == 1);
    }
    for (int i = 1; i <= m; i++)
        cout << res[r[i]] - res[l[i] - 1] + sum << endl;
    return 0;
}