// 四种情况
// 1 1
// 1 2
// 2 1
// 2 2 矛盾，X
// 其中，23是互斥的，且都有可能和1重复

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
char s[N];
int e[N]; // e的值为 当前羊写到的最大下标

int main()
{
    scanf("%d%s", &n, s + 1); // 这个输入学到了，字符串从下标为1开始了

    // 化字母为数字
    for (int i = 1; i <= n; i++)
        if (s[i] == 'G')
            s[i] = 0;
        else
            s[i] = 1;

    for (int i = 1; i <= n; i++)
        scanf("%d", &e[i]);

    int l[2] = {n, n}, r[2] = {1, 1}; // l[0]是G出现在最左边的下标，l[1]是H出现在最左边的下标。r同理
    for (int i = 1; i <= n; i++)
    {
        int t = s[i]; // 可能为0/1。这里太巧妙，可能这个写法就是做题积累起来的
        l[t] = min(l[t], i);
        r[t] = max(r[t], i);
    }

    int res = 0;
    // 判断1 1的情况
    if (e[l[0]] >= r[0] && e[l[1]] >= r[1])
        res++;

    // 判断12 21(互斥)的情况
    int a = s[1];
    int b = !s[1];       // 注意这个写法，a取首字母（我们并不知道a是什么），b也未知，但可以取反
    if (e[l[b]] >= r[b]) // 保证后出现的字母（即b）满足1
    {
        for (int i = 1; i < l[b]; i++)
        {
            if (e[i] >= l[b]) // 找先出现的字母（即a）满足2的个数
                res++;
        }
    }
    // 判断11 12/21 重复的情况
    if (e[1] >= r[a] && e[1] >= l[b]) // 前半句满足11
        res--;

    printf("%d", res);
    return 0;
}