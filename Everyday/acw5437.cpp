#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m;
ll a[N]; // 牛吃糖长高可能要爆int
int b[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);

    // 外层遍历糖
    for (int i = 1; i <= m; i++)
    {
        // 记录当前糖已经吃了的部分，即离地的高度。读题，下端总是垂地的
        int t = 0;
        for (int j = 1; j <= n; j++)
        {
            // 如果牛够不到糖
            if (a[j] <= t)
                continue;
            // 吃到与身高齐平，但可能牛本身就高于糖
            int eat = min(a[j], (ll)b[i]) - t; // 强转是min函数参数要求相同
            a[j] += eat;
            t += eat;

            if (t == b[i]) // 如果糖吃完了
                break;     // 跳出一层，换到下个糖
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%lld\n", a[i]);

    return 0;
}