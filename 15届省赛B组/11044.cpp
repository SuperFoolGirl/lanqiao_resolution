// 贪心逻辑：每张桌子必须尽可能坐满
#include <iostream>
#include <algorithm>

using namespace std;

int q, a2, a3, a4, b4, b6, ans;

int main()
{
    cin >> q;
    while (q--)
    {
        cin >> a2 >> a3 >> a4 >> b4 >> b6;
        ans = 0;
        // 满
        while (a4 > 0 && b4 > 0)
        {
            ans += 4;
            a4--;
            b4--;
        }
        while (a4 > 0 && a2 > 0 && b6 > 0)
        {
            ans += 6;
            a4--;
            a2--;
            b6--;
        }
        while (a3 - 1 > 0 && b6 > 0)
        {
            ans += 6;
            a3 -= 2;
            b6--;
        }
        while (a2 - 2 > 0 && b6 > 0)
        {
            ans += 6;
            a2 -= 3;
            b6--;
        }
        while (a2 - 1 > 0 && b4 > 0)
        {
            ans += 4;
            a2 -= 2;
            b4--;
        }
        // 空1
        while (a2 > 0 && a3 > 0 && b6 > 0)
        {
            ans += 5;
            a2--;
            a3--;
            b6--;
        }
        while (a3 > 0 && b4 > 0)
        {
            ans += 3;
            a3--;
            b4--;
        }
        // 空2
        while (a4 > 0 && b6 > 0)
        {
            ans += 4;
            a4--;
            b6--;
        }
        while (a2 - 1 > 0 && b6 > 0)
        {
            ans += 4;
            a2 -= 2;
            b6--;
        }
        while (a2 > 0 && b4 > 0)
        {
            ans += 2;
            a2--;
            b4--;
        }
        // 空3
        while (a3 > 0 && b6 > 0)
        {
            ans += 3;
            a3--;
            b6--;
        }
        // 空4
        while (a2 > 0 && b6 > 0)
        {
            ans += 2;
            a2--;
            b6--;
        }
        cout << ans << endl;
    }
    return 0;
}