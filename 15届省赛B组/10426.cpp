// 一个都没过
#include <cstdio>
using namespace std;

int arr[100010] = {0};
int n;
int ans[3] = {0};
int now[3] = {0};
int s_max = 0;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int s(int a, int b, int c)
{
    return a * b * c * lcm(lcm(a, b), c) / lcm(a, b) / lcm(a, c) / lcm(b, c);
}

void dfs(int x, int start)
{
    if (x == 3)
    {
        int ret = s(arr[now[0]], arr[now[1]], arr[now[2]]);
        if (ret > s_max)
        {
            s_max = ret;
            for (int i = 0; i < 3; i++)
                ans[i] = now[i];
        }
    }
    for (int i = start; i < n; i++)
    {
        now[x] = i;
        dfs(x + 1, i + 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    dfs(0, 0);
    for (int i = 0; i < 3; i++)
        printf("%d ", arr[ans[i]]);
    return 0;
}