// 暴力

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int N = 300010;

int n;
int a[100010];
int cnt[100010];

int main()
{
    cin >> n;
    int idx = 1;
    int next = -1;
    while (N--)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i]++;
            cnt[i] = max(cnt[i], a[i]);
        }
        a[idx] = 0;
        if (idx == n)
            next = -next;
        if (idx == 1)
            next = -next;
        idx += next;
    }
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << endl;
    return 0;
}