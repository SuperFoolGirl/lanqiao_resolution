#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 7510;

int n;
int a[N], b[N];
int sum;
int ans[N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == b[i])
            cnt++;

    // 枚举反转区间
    // i遍历反转中心点，j遍历中心为奇数/偶数，内层循环按中心扩散
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum = cnt;
            for (int l = i, r = i + j; l >= 1 && r <= n; l--, r++)
            {
                if (a[l] == b[l])
                    sum--;
                if (a[r] == b[r])
                    sum--;
                // 交换
                if (a[l] == b[r])
                    sum++;
                if (a[r] == b[l])
                    sum++;

                // 此时呈现出了可以体检sum头牛的状态。最后要输出sum在各值时的方案总数
                ans[sum]++;
            }
        }
    }

    for (int i = 0; i <= n; i++)
        printf("%d\n", ans[i]);

    return 0;
}