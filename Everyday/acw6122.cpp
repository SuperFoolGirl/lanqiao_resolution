#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1010;

int n, q;
int a[N][N], b[N][N], c[N][N]; // 开三个二维数组来记录三个坐标系--XOY, XOY, ZOX

int main()
{
    int ans = 0;
    scanf("%d%d", &n, &q);
    while (q--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (++a[x][y] == n)
            ans++;
        if (++b[y][z] == n)
            ans++;
        if (++c[x][z] == n)
            ans++;
        printf("%d\n", ans);
    }
    return 0;
}