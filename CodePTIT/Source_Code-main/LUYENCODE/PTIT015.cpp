#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
vector<string> a;
void BackTracking(string s, int open, int close)
{
    if (open == 0 && close == 0)
    {
        a.push_back(s);
        return;
    }
    if (open)
        BackTracking(s + '(', open - 1, close);
    if (close > open)
        BackTracking(s + ')', open, close - 1);
}
int main()
{
    int n;
    cin >> n;
    BackTracking("", n / 2, n / 2);
    sort(a.begin(), a.end());
    for (auto x : a)
        cout << x << "\n";
    cout << (int)a.size();
    return 0;
}
