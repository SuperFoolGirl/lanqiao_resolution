// 好数
// 自己写的就是一坨
#include <iostream>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x = i;

        int flag = 1;
        int defeat = 0;
        while (x)
        {
            if (flag == 1) // 奇数位
            {
                if (x % 10 % 2 == 1)
                {
                    flag = 0;
                    x /= 10;
                }
                else
                {
                    defeat = 1;
                    break;
                }
            }
            else
            {
                if (x % 10 % 2 == 0)
                {
                    flag = 1;
                    x /= 10;
                }
                else
                {
                    defeat = 1;
                    break;
                }
            }
        }
        if (!defeat)
            ans++;
    }
    cout << ans;
    return 0;
}

// 一个优秀很多很多的解法