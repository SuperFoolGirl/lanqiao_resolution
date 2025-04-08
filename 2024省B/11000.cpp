// AI逆天DP

#include <iostream>
typedef long long ll;
const int mod = 1e9 + 7;
const int n = 10000;

int main()
{
    ll dp[n + 1][2][2];
    // 初始化
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // 从没有3和7的状态转移
        dp[i][0][0] = dp[i - 1][0][0] * 7 % mod;
        // 从没有7但有3的状态转移
        dp[i][1][0] = (dp[i - 1][1][0] * 8 + dp[i - 1][0][0]) % mod;
        // 从没有3但有7的状态转移
        dp[i][0][1] = (dp[i - 1][0][1] * 8 + dp[i - 1][0][0]) % mod;
        // 从有3和7的状态转移
        dp[i][1][1] = (dp[i - 1][1][1] * 9 + dp[i - 1][1][0] + dp[i - 1][0][1]) % mod;
    }
    std::cout << dp[n][1][1] << std::endl;
    return 0;
}