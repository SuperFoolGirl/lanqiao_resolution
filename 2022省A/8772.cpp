#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 200010;

int n;
ll a[N];
ll s;
ll sum[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
        s += a[i] * (sum[n] - sum[i]);
    cout << s << endl;
    return 0;
}