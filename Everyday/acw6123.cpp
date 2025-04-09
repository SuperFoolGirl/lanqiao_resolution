#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010, M = 26;

int n, f;
char s[N];
int cnt[M][M]; // 用二维数组统计abb出现次数即可
bool st[M][M];

void update(int l, int r, int v)
{
    l = max(0, l), r = min(n - 1, r); // 保证统计不越界
    for (int i = l; i + 2 <= r; i++)
    {
        char a = s[i], b = s[i + 1], c = s[i + 2];
        if (a != b && b == c)
        {
            cnt[a][b] += v;
            if (cnt[a][b] >= f)
                st[a][b] = true;
        }
    }
}

int main()
{
    scanf("%d%d%s", &n, &f, s);

    // 将字母字符转换为数字
    for (int i = 0; i < n; i++)
        s[i] -= 'a';

    // 统计原串
    update(0, n - 1, 1);

    for (int i = 0; i < n; i++)
    {
        char t = s[i];
        update(i - 2, i + 2, -1); // 去掉一个字符，最多影响到前后两个字符

        // 枚举修改的字符
        for (int j = 0; j < M; j++)
        {
            if (t != j) // 原字符跳过
            {
                s[i] = j;
                update(i - 2, i + 2, 1);  // 加上一个字符，最多影响到前后两个字符
                update(i - 2, i + 2, -1); // 恢复现场（对称）
            }
        }

        // 恢复现场（对称）
        s[i] = t;
        update(i - 2, i + 2, 1);
    }

    int res = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (st[i][j])
                res++;
        }
    }
    printf("%d\n", res);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (st[i][j])
                printf("%c%c%c\n", i + 'a', j + 'a', j + 'a');
        }
    }

    return 0;
}