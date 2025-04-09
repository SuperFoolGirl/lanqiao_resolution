// 转化为区间覆盖问题

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 300010;

int n;
char s[N];
vector<int> cnt;

int main()
{
    scanf("%d%s", &n, s);

    int r = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            continue;

        // 双指针找到1组成的区间
        int j = i + 1;
        while (j < n && s[j] == '1')
            j++;

        int c = j - i;       // 1的个数，即区间长度
        int d = (c - 1) / 2; // 传染这么大范围所需要的天数

        if (!i || j == n) // 如果是边界，传染需要特判
            d = c - 1;

        r = min(r, d); // r在遍历所有传染区间时，维护最小天数

        cnt.push_back(c);
        i = j; // 跳过1的区间，之后正好执行i++，来到下一个0
    }

    int res = 0;
    for (int c : cnt)
        res += (c + r * 2) / (r * 2 + 1); // 上取整计算公式：分母不变，分子加上(分母-1)
    printf("%d", res);

    return 0;
}