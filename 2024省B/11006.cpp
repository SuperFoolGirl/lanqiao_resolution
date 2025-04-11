// 思路有问题

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 100010;

LL k;
int T, n;
map<int, LL> b; // 统计各职业士兵人数，因为ab范围太大，没法开数组
vector<pair<int, int>> ans;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        b.clear();
        ans.clear();

        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            b[x] += y;
        }

        LL res = 0;
        LL team = 0;
        // 所有人先减去2，不满2的减1
        for (auto t : b)
        {
            int val = t.second;
            if (val >= 2)
            {
                res += 2;
                t.second -= 2;
            }
            else
            {
                res += val;
                t.second = 0;
            }
        }
        // 减去后，每个组只要再加一个士兵就可以组成小队了，但是为了最大化，能加3就加3，随后是2，最后才考虑1
        for (auto t : b)
        {
            int val = t.second;
            ans.push_back({val / 3, val % 3});
        }
        sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.second > b.second; }); // 匿名函数，无需命名
        for (auto &t : ans)
        {
            team += t.first;
            res += t.second;

            if (team >= k)
                break; // 直接退出，不要逗留。能白嫖的已经嫖完了
        }

        if (team >= k)
            printf("%lld\n", k * 3 + res);
        else
            puts("-1");
    }
    return 0;
}