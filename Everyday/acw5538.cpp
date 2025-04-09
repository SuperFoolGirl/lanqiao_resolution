// 必胜态：存在一种操作方式，让对手编程必败态
// 必败态：不论怎么操作，对手都会变成必胜态

// 如果末尾是0，必败
// 如果末尾不是1，必胜
// 数学归纳法证明

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string s; // 不需要头文件就可以用？
        cin >> s;
        if (s.back() == '0')
            cout << 'E' << endl;
        else
            cout << 'B' << endl;
    }
    return 0;
}