#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e8;

int ansA, ansB;
int cnt;
vector<int> v;

bool check(int x)
{
    cnt = 0;
    v.clear();
    while (x)
    {
        v.push_back(x % 10);
        x /= 10;
        cnt++;
    }
    return (!(cnt & 1));
}

void problemA()
{
    for (int i = 1; i <= N; i++)
    {
        if (check(i))
        {
            int right = 0;
            for (int i = 0; i < cnt / 2; i++)
                right += v[i];
            int left = 0;
            for (int i = cnt / 2; i < cnt; i++)
                left += v[i];
            if (right == left)
                ansA++;
        }
    }
}

void dfs(int x, int points)
{
    if (points == 100)
    {
        return;
    }

    if (x == 30)
    {
        if (points == 70)
            ansB++;
        return;
    }

    // 答对
    dfs(x + 1, points + 10);

    // 答错
    dfs(x + 1, 0);
}

void problemB()
{
    dfs(0, 0);
}

int main()
{
    char pid;
    cin >> pid;
    if (pid == 'A')
    {
        // problemA();
        printf("4430091");
    }
    else
    {
        // problemB();
        printf("4165637");
    }
    return 0;
}