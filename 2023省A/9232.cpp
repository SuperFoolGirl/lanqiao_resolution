// 暴力

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

string s;
vector<int> s_int;
vector<int> orig_int;

bool check(string s, int n)
{
    // 两个高精度数组
    for (int i = 0; i < n; i++)
        orig_int[i] = s[i] - '0';

    for (int i = 0; i < n; i++)
        s_int[i] = s[n - i - 1] - '0';

    for (int i = 0; i < n; i++)
        if (s_int[i] < orig_int[i])
            return true;
        else if (s_int[i] > orig_int[i])
            return false;
        else
            ;
    return false;
}

int main()
{
    ll res = 0;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            s_int.clear();
            orig_int.clear();
            s_int.resize(j - i + 1);
            orig_int.resize(j - i + 1);

            if (check(s.substr(i, j - i + 1), j - i + 1))
            {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}