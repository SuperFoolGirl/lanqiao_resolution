// 暴力dfs，TLE

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int n, m, k;
int res = 1e9;
int a[110][25];
int ans[25];

bool check()
{
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == 0)
            return false;
    }
    return true;
}

void add(int x)
{
    int *arr = a[x];
    for (int i = 1; i <= k; i++)
    {
        ans[a[x][i]]++;
    }
}

void diff(int x)
{
    int *arr = a[x];
    for (int i = 1; i <= k; i++)
    {
        ans[a[x][i]]--;
    }
}

void dfs(int x, int select)
{
    if (check())
    {
        res = min(res, select);
        return;
    }

    if (x > n)
    {
        return;
    }

    // 选第x包
    add(x);
    dfs(x + 1, select + 1);
    diff(x);

    // 不选第x包
    dfs(x + 1, select);
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            cin >> a[i][j];

    dfs(1, 0);
    cout << res;
    return 0;
}