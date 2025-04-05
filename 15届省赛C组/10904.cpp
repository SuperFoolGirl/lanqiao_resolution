// 暴力，样例过了，但全部TLE

#include <iostream>
#include <algorithm>

using namespace std;

const int N1 = 100010;
const int N2 = 1000000;

int n, m;
int ans = 0;
int a[N1];
bool b[N2 * 2];

void dfs(int x, int step, int s)
{
    if (m + 1 == step)
    {
        ans = max(ans, s);
        return;
    }

    for (int i : {1, -1})
    {
        int next = x + i;
        if (next < 0 || next > 2 * N2)
            continue;
        if (b[next])
        {
            b[next] = false;
            dfs(next, step + 1, s + 1);
            b[next] = true;
        }
        else
        {
            dfs(next, step + 1, s);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        int x = a[i] + N2;
        b[x] = true;
    }

    dfs(N2, 0, 0);
    cout << ans;
    return 0;
}