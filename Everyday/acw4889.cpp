#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 25, M = 15, K = 110;

int n, m;

struct Cow
{
    int s, t, c;
} cow[N];

struct Ac
{
    int a, b, p, m;
} ac[M];

int w[K];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int s, t, c;
        scanf("%d%d%d", &s, &t, &c);
        cow[i] = {s, t, c};
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, p, m;
        scanf("%d%d%d%d", &a, &b, &p, &m);
        ac[i] = {a, b, p, m};
    }

    // 指数型枚举，可以用dfs或二进制位运算
    // 枚举m个空调开或不开
    int res = 1e8;                     // 初始化一个大数，一般是用来后面更新min
    for (int i = 0; i < (1 << m); i++) // 枚举每一种情况
    {
        memset(w, 0, sizeof w); // w数组记录牛栏温度
        int cost = 0;

        for (int j = 0; j < m; j++) // 枚举每种情况下空调的情况
            if ((i >> j) & 1)       // 如果二进制数i的第j位为1(这个位置是空调)
            {
                // 注意ac下标取j，因为j是空调
                int a = ac[j].a, b = ac[j].b, p = ac[j].p, m = ac[j].m; // 第一行取出空调的参数，省的后面太乱
                cost += m;
                for (int k = a; k <= b; k++)
                    w[k] += p;
            }

        bool satisfy = true;
        for (int j = 0; j < n; j++)
        {
            int s = cow[j].s, t = cow[j].t, c = cow[j].c; // 取出牛栏的参数
            for (int k = s; k <= t; k++)
                if (w[k] < c)
                {
                    satisfy = false;
                    break;
                }
        }

        if (satisfy)
            res = min(res, cost);
    }
    printf("%d", res);
    return 0;
}