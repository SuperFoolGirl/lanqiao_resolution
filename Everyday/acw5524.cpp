// 如果连续三个奶牛中有两个喜欢同一种草，那么就可以蔓延到全部

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 100010;

int n;
vector<int> p[N]; // 这是二维数组，共n行，每行都是一个动态数组

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);
        // 二维数组需要逐行清空
        for (int i = 1; i <= n; i++)
            p[i].clear();

        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            p[x].push_back(i); // 记录每种草的支持者序号
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)                  // 遍历草的种类，草的种类范围为1~n，n同时为奶牛个数
            for (int j = 0; j + 1 < p[i].size(); j++) // 遍历每种草的支持者 循环条件防止下方j+1越界
                if (p[i][j + 1] - p[i][j] <= 2)       // 看相邻两个支持者的距离是否<=2
                {
                    printf("%d ", i);
                    cnt++;
                    break;
                }

        if (!cnt)
            printf("-1");
        puts("");
    }
    return 0;
}