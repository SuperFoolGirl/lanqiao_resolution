// R格式

#include <iostream>
#include <string>
using namespace std;

string d;
int n;
int bit = 0;
int mult[2000] = {0};

int main()
{
    cin >> n >> d;
    int len = d.length() - 1; // 去掉小数点后的长度

    for (int i = 0;; i++)
    {
        if (d[i] == '.')
        {
            bit = len - i; // 小数点后有几位
            d.erase(i, 1); // 先把小数点删掉
            break;
        }
    }

    for (int i = 0, j = len - 1; i < len; i++, j--)
        mult[i] = d[j] - '0';

    for (int i = 0; i < n; i++)
    {
        // 每一位乘2
        for (int j = 0; j < len; j++)
            mult[j] *= 2;
        // 压缩
        for (int j = 0; j < len; j++)
        {
            if (mult[j] >= 10)
            {
                mult[j + 1] += mult[j] / 10;
                mult[j] %= 10;
            }
        }
        // 处理进位
        if (mult[len])
            len++;
    }

    // 遍历到小数点后的第一位，进行四舍五入
    if (mult[bit - 1] >= 5)
        mult[bit]++;

    // 处理整数部分可能存在的进位
    int now = bit;
    while (mult[now] >= 10)
    {
        mult[now + 1] += mult[now] / 10;
        mult[now] %= 10;
        now++;
    }
    // 处理可能由进位导致的长度变化，虽然概率很小很小
    if (now >= len)
        len = now + 1;

    // 输出
    for (int i = len - 1; i >= bit; i--)
        cout << mult[i];
    return 0;
}







// 统一一下高精度更舒适、整洁的写法
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void mul(vector<int> &num, int x)
{
    int carry = 0; // 进位保证是int
    for (int i = 0; i < num.size(); i++)
    {
        carry += num[i] * x; // 注意这里加等，因为存储着上一次的进位
        num[i] = carry % 10; // 本位的值
        carry /= 10;         // 进位
    }
    if (carry) // 高精度乘低精度，就乘一位数，最多进一位。用push_back很方便
        num.push_back(carry);
}

void add(vector<int> &num, int dot, int carry)
{
    // carry已经有了，这里不用再定义
    for (int i = dot; i < num.size(); i++)
    {
        carry += num[i];     // 加上本位
        num[i] = carry % 10; // 本位的值
        carry /= 10;         // 进位
    }
    if (carry)
        num.push_back(carry);
}

int main()
{
    int n;
    string d;
    cin >> n >> d;

    reverse(d.begin(), d.end()); // 直接反转字符串，省的后续自己还要注意变方向
    int dot = d.find('.');       // 找到小数点的位置
    vector<int> num;
    for (auto c : d) // 字符串已经反转了，直接遍历即可
        if (c != '.')
            num.push_back(c - '0');

    // 乘以2的n次方
    while (n--)
        mul(num, 2);

    // 这里遍历向量，注意dot从一开始就没加
    if (num[dot - 1] >= 5)
        add(num, dot, 1); // dot此时是个位，1是进位

    for (int i = num.size() - 1; i >= dot; i--)
        cout << num[i];
    return 0;
}