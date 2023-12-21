#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node
{
    string str;
    int step;
};
string Rotate_Left(string s)
{
    string res = s;
    res[0] = s[3], res[1] = s[0], res[3] = s[7], res[5] = s[1], res[7] = s[8], res[8] = s[5];
    return res;
}
string Rotate_Right(string s)
{
    string res = s;
    res[1] = s[4], res[2] = s[1], res[4] = s[8], res[6] = s[2], res[8] = s[9], res[9] = s[6];
    return res;
}
string Counter_Rotate_Left(string s)
{
    string res = s;
    res[0] = s[1], res[1] = s[5], res[3] = s[0], res[5] = s[8], res[7] = s[3], res[8] = s[7];
    return res;
}
string Counter_Rotate_Right(string s)
{
    string res = s;
    res[1] = s[2], res[2] = s[6], res[4] = s[1], res[6] = s[9], res[8] = s[4], res[9] = s[8];
    return res;
}
void Solve()
{
    string start = "", end = "1238004765";
    for (int i = 0; i < 10; i++)
    {
        int num;
        cin >> num;
        start += to_string(num);
    }
    unordered_map<string, int> vis_s, vis_e;
    queue<Node> q1, q2;
    q1.push({start, 0});
    q2.push({end, 0});
    vis_s[start] = vis_e[end] = 0;
    while (!q1.empty() && !q2.empty())
    {
        Node cur1 = q1.front();
        q1.pop();
        if (cur1.str == end)
        {
            cout << cur1.step << "\n";
            return;
        }
        if (vis_e.count(cur1.str))
        {
            cout << cur1.step + vis_e[cur1.str] << "\n";
            return;
        }
        string L = Rotate_Left(cur1.str), R = Rotate_Right(cur1.str);
        for (auto x : {L, R})
        {
            if (vis_s.count(x) == 0)
            {
                q1.push({x, cur1.step + 1});
                vis_s[x] = cur1.step + 1;
            }
        }
        Node cur2 = q2.front();
        q2.pop();
        if (cur2.str == start)
        {
            cout << cur2.step << "\n";
            return;
        }
        if (vis_s.count(cur2.str))
        {
            cout << cur2.step + vis_s[cur2.str] << "\n";
            return;
        }
        L = Counter_Rotate_Left(cur2.str), R = Counter_Rotate_Right(cur2.str);
        for (auto x : {L, R})
        {
            if (vis_e.count(x) == 0)
            {
                q2.push({x, cur2.step + 1});
                vis_e[x] = cur2.step + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
