// 数字接龙
// 题号 3212
// 一个点没过

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, k;
vector<vector<int>> g;
vector<vector<bool>> vis;
vector<int> ans;

void dfs(int x, int y, int now)
{
    // 出口
    if (x == n - 1 && y == n - 1)
    {
        if (ans.size() == n * n - 1)
        {
            // 如果找到了路径，此时一定是字典序最小，直接输出然后强制退出
            for (int i = 0; i < n * n - 1; i++)
            {
                cout << ans[i];
            }
            exit(0);
        }
        return;
    }

    // 跑图
    for (int i = 0; i < 8; i++) // 字典序
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 越界判断
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        // 访问判断
        if (vis[nx][ny])
            continue;

        // 交叉路径判断 4个
        // 注意xy的范围
        if (i == 1 && x >= 1 && y < n - 1)
        {
            if (vis[x - 1][y] == true && vis[x][y + 1] == true)
                continue;
        }
        if (i == 3 && x < n - 1 && y < n - 1)
        {
            if (vis[x][y + 1] == true && vis[x + 1][y] == true)
                continue;
        }
        if (i == 5 && x < n - 1 && y >= 1)
        {
            if (vis[x][y - 1] == true && vis[x + 1][y] == true)
                continue;
        }
        if (i == 7 && x >= 1 && y >= 1)
        {
            if (vis[x - 1][y] == true && vis[x][y - 1] == true)
                continue;
        }

        // 所走值的合法性判断
        if ((now + 1) % k != g[nx][ny])
            continue;

        vis[nx][ny] = true;
        ans.push_back(i);
        dfs(nx, ny, (now + 1) % k);
        vis[nx][ny] = false;
        ans.pop_back();
    }
}

int main()
{
    cin >> n >> k;
    g.resize(n, vector<int>(n));
    vis.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    vis[0][0] = true; // 起点预处理
    dfs(0, 0, 0);
    // 如果找到路径，会在dfs中直接输出，这里如果到了这里说明没找到
    cout << "-1" << endl;
    return 0;
}