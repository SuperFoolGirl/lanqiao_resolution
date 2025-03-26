#include <cstdio>
#include <iostream>
#include <vector>
#define MAXN 1000010
using namespace std;

int main()
{
    long long n, s;
    scanf("%lld %lld", &n, &s);
    vector<long long> p(n + 1, 0);
    vector<long long> c(n + 1, 0);
    vector<long long> cnt(MAXN, 0);

    long long tot = 0, sum = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &p[i], &c[i]);
        cnt[c[i]] += p[i];
        tot += p[i];
        ans += p[i] * c[i];
    }
    for (int i = 1; i <= MAXN; i++)
    {
        if (tot < s)
            break;
        sum += s;
        ans -= tot;
        tot -= cnt[i];
    }
    printf("%lld\n", ans + sum);
    return 0;
}