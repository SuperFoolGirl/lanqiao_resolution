// 注意算法标签给出的：贪心

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int a[N];
int res = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
            continue;

        res++;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] == i)
            {
                swap(a[i], a[j]); // 标准库函数
                break;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}