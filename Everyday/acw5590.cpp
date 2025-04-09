#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const int N = 200010, M = 1010;

int n, m;
PII q[N];
int s[M][M]; // 前缀和

int get(int x, int tx) // 提供移动方向判断
{
    if (x < tx)
        return 1;
    if (x > tx)
        return -1;
    return 0;
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &q[i].x, &q[i].y);

    int sum = 0, x = q[n - 1].x, y = q[n - 1].y; // 设第n-1个为起点，正好下面for遍历0-n
    for (int i = 0; i < n; i++)
    {
        int tx = q[i].x, ty = q[i].y; // targetX, targetY
        int vx = get(x, tx), vy = get(y, ty);

        while (x != tx || y != ty) // 没有到达本条篱笆的终点的话
        {
            x += vx, y += vy;
            s[x][y] = ++sum; // 记录前缀和，s[x][y]表示到达(x,y)所需的步数
        }
    }

    while (m--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int dist = s[x2][y2] - s[x1][y1]; // 计算前缀和差值，即两点间所需步数
        if (dist < 0)
            dist += sum;
        printf("%d\n", min(dist, sum - dist)); // 取最小值，正向和反向都可以到达
    }
    return 0;
}