// 模拟水题，自己写的代码输入可能存在问题，只能本地过样例，不过getline学到了，和gets作用差不多

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int t;
int tm[4];
string s[4];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s[0]; // cin不接受空白字符
        getchar();
        getline(cin, s[1]); // getline可接受空格，不接受换行符，并将换行符从缓冲区中清除。是string类的方法
        cin >> s[2];
        getchar();
        getline(cin, s[3]);

        for (int i = 0; i < 4; i++)
        {
            int num1 = (s[i][0] - '0') * 10 + (s[i][1] - '0');
            int num2 = (s[i][3] - '0') * 10 + (s[i][4] - '0');
            int num3 = (s[i][6] - '0') * 10 + (s[i][7] - '0');
            if (s[i].length() > 8)
                num1 += (s[i][11] - '0') * 24;
            tm[i] = num1 * 3600 + num2 * 60 + num3;
        }
        int ans = 0;                               // ans记录总秒数
        ans = (tm[1] - tm[0] + tm[3] - tm[2]) / 2; // 注意 这里是计算时差，往返求平均值
        int hour = ans / 3600;
        int min = (ans % 3600) / 60; // 模3600后得到剩余的秒数，再除以60得到分钟数
        int sec = ans % 60;          // 直接模60后得到剩余的秒数，秒的范围就是0-59，符合余数定义

        if (hour < 10)
            cout << "0" << hour << ":";
        else
            cout << hour << ":";

        if (min < 10)
            cout << "0" << min << ":";
        else
            cout << min << ":";

        if (sec < 10)
            cout << "0" << sec << endl;
        else
            cout << sec << endl;
    }
    return 0;
}



// AC代码
// 神一般的scanf用法，学到了
// 还有这个getchar()，我的天，试探性输入

#include <bits/stdc++.h>
using namespace std;

int get()
{
    int h1, m1, s1, h2, m2, s2, d = 0;
    scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2); // 用整形直接接收，避免使用字符串，这个格式控制太巧妙了，终于会用scanf了
    // 这两句更是神中神
    if (getchar() == ' ')
        scanf("(+%d)", &d);
    return (d * 86400 + h2 * 3600 + m2 * 60 + s2) - (h1 * 3600 + m1 * 60 + s1);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int ans = get() + get() >> 1; // 求平均值
        printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60); // printf格式化输出，%02d表示输出两位数，不足两位前面补0
    }
    return 0;
}