// 爬山
// 3213
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    priority_queue<int> pq;
    int n, p, q;
    cin >> n >> p >> q;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        pq.push(h);
    }

    while (p || q)
    {
        auto t = pq.top();
        pq.pop();

        int sqrt_res = sqrt(t);
        int div_res = t / 2;

        if (p)
        {
            if (q)
            {
                if (sqrt_res <= div_res)
                {
                    pq.push(sqrt_res);
                    p--;
                }
                else
                {
                    pq.push(div_res);
                    q--;
                }
            }
            else
            {
                pq.push(sqrt_res);
                p--;
            }
        }
        else // p已经没了
        {
            if (q)
            {
                pq.push(div_res);
                q--;
            }
            else
                break;
        }
    }

    long long ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}