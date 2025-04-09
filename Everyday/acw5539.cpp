#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 400010;

int n, m;
char str[N];
int w[N];

int main()
{
    scanf("%d%d%s", &n, &m, str);
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        res += w[i];         // 记录牛奶总量
        str[i + n] = str[i]; // 破环成链，再续一条
        w[i + n] = w[i];     // 续一条链的牛奶量
    }

    int k = 0;
    while (k < n && str[k] == str[k + 1])
        k++; // 找到第一个不同的朝向，k+1作为起点

    if (k < n) // 翻译一下，就是存在不同的方向，而非全是L/R。如果只有一个方向，那不会浪费牛奶。
    {
        // 每次循环遍历一整个朝向
        for (int i = k + 1; i <= n; i++) // k+1是起点
        {
            int j = i;
            ll sum = 0;
            // 双指针j来找L/R的分界
            while (j <= k + n && str[j] == str[i]) // 由于起点在第一条链内，需要越界直到k+n，视为一条完整的链
            {
                sum += w[j]; // 计算当前可能被浪费的牛奶总量
                j++;
            }

            if (str[i] == 'R')
                sum -= w[j - 1]; // 如果是R，最后一桶牛奶不算在内，无限循环，永远不可能浪费
            else
                sum -= w[i]; // 如果是L，第一桶牛奶不算在内。

            res -= min(sum, (ll)m); // 减去浪费量。随着时间推移，牛奶越来越少，浪费越来越多。对于每一侧，每分钟浪费一桶；共m分钟，最多只能浪费m桶

            i = j - 1; // j是下一个朝向的第一个牛奶桶，正好配合i++
        }
    }

    printf("%lld", res); // 输出剩余牛奶总量
    return 0;
}