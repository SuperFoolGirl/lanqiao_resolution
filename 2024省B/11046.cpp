// 关于传送门的处理：无向边
// 本题用不了并查集，更用不上图论
// 注意一下对于传送门的处理：二维数组
// 我现在对于数组的使用能力确实太差了

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef long double LD;

const int N = 5010;

int n, m, q;
vector<int> g[N]; // 记录传送门
int dist[N];      // 到达某个星球所需要的最小步数
queue<int> que;

int bfs(int x, int y)
{
    // 多次调用bfs，清空痕迹
    memset(dist, -1, sizeof dist);
    while (!que.empty())
        que.pop();

    dist[x] = 0;
    que.push(x);

    int sum = 1; // 统计本轮bfs答案，至少一个
    while (!que.empty())
    {
        auto t = que.front();
        que.pop();

        // 如果达到步数
        if (dist[t] == y)
            break;

        // 列出所有可传送的地点
        int len = g[t].size();
        for (int i = 0; i < len; i++)
        {
            // 如果被访问过了，跳过
            if (dist[g[t][i]] != -1)
                continue;

            dist[g[t][i]] = dist[t] + 1;
            sum++;
            que.push(g[t][i]);
        }
    }
    return sum; // 注意返回临时变量，生命周期只有函数内
}

int main()
{
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        // 无向边，双向处理
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int res = 0;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        res += bfs(x, y);
    }

    printf("%.2lf", 1.0 * res / q);
    return 0;
}