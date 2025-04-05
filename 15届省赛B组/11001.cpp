// 暴力
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int g[N][N];
int ans = 0;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &g[i][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a = g[i][j];
            // 注意kl的初始化
            for (int k = i + 1; k <= n; k++)
            {
                for (int l = 1; l <= m; l++)
                {
                    int b = g[k][l];

                    if (a == b && abs(i - k) == abs(j - l) && i != k && j != l)
                    {
                        ans += 2;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}