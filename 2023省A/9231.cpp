// 数论
/*
得到 x=(y−z)×(y+z)，可知 x 满足可以拆成 2 个奇偶性相同的数的乘积。
如果是奇数，直接拆成 1 和它本身即可。
如果是偶数，因为要拆成 2 个偶数，所以应是 4 的倍数，此时一种拆分为拆成 2 和 x 除以 2。
至此，答案为 l 到 r 中奇数和 4 的倍数的个数。
*/

#include <bits/stdc++.h>

using namespace std;

int f(int x)
{ // 小于等于x的奇数个数
    if (!x)
        return 0;
    return (x + 1) / 2;
}

int g(int x)
{ // 小于等于x的4的倍数个数
    return x / 4;
}

int main()
{
    int l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) + g(r) - g(l - 1);
    return 0;
}