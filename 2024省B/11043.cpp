// vice_idx是一个不断变化的数组，每次查询时能直接访问最小值
// 最小堆不行，因为需要索引来访问节点，最小堆必须pop掉之后重新push，也无法用索引来找到节点

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;

int n, q;
int main_arr;    // 根本不需要存具体数值，甚至可以不统计个数，直接无视add操作
int vice_idx[N]; // 副本数组，vice_idx[i]表示第i个副本所包含的元素
string s;
int ans = 1e9; // 维护副本数组元素的最小值，这个最小值就是每次查询时的答案

int main()
{
    cin >> n;
    getchar();
    while (getline(cin, s)) // 需要读空格
    {
        if (s.find("add") != string::npos) // 注意判断逻辑，不能舍弃后面的string::nops，否则若add出现在开头，返回0
        {
            main_arr++;
        }
        else if (s.find("query") != string::npos)
        {
            // 对于每次询问，需要更新ans
            ans = 1e9; // 每次询问都要重新计算最小值
            for (int i = 1; i <= n - 1; i++)
                ans = min(ans, vice_idx[i]);
            cout << ans << endl;
        }
        else // sync
        {
            int op = s.back() - '0';
            vice_idx[op]++;
        }
    }
    return 0;
}