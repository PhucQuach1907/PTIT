#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    deque<int> q;
    while (Q--)
    {
        string s;
        cin >> s;
        if (s == "PUSHBACK")
        {
            int num;
            cin >> num;
            q.push_back(num);
        }
        else if (s == "PUSHFRONT")
        {
            int num;
            cin >> num;
            q.push_front(num);
        }
        else if (s == "POPBACK")
        {
            if (!q.empty())
                q.pop_back();
        }
        else if (s == "POPFRONT" && !q.empty())
        {
            if (!q.empty())
                q.pop_front();
        }
        else if (s == "PRINTBACK")
            cout
                << (q.empty() ? "NONE" : to_string(q.back())) << "\n";
        else if (s == "PRINTFRONT")
            cout << (q.empty() ? "NONE" : to_string(q.front())) << "\n";
    }
    return 0;
}
