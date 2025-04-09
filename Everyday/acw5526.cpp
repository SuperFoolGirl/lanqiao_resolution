// 差分和多次差分
// 等差数列求一次差分为常数
// 常数再求差分为0
// 求差分类似求导，但仅限于幂函数

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 200010;

int n;
ll a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    for (int i = n; i >= 1; i--)
        a[i] -= a[i - 1]; // 直接对原数组求差分，但需要倒序求

    ll res = 0;
    for (int i = n; i >= 1; i--)
        res += abs(a[i] - a[i - 1]); // 再求差分，这里顺便直接完成题目要求

    printf("%lld", res);
    return 0;
}