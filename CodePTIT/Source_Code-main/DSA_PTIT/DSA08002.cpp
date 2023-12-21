#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    queue<int> qq;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "PUSH")
        {
            int num;
            cin >> num;
            qq.push(num);
        }
        else if (s == "POP")
        {
            if (!qq.empty())
                qq.pop();
        }
        else
            cout << (qq.empty() ? "NONE" : to_string(qq.front())) << "\n";
    }
    return 0;
}
