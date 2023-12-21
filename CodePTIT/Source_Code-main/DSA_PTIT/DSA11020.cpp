#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool isInorderTraversal(vector<int> a)
{
    vector<int> b = a;
    sort(b.begin(), b.end());
    if (adjacent_find(b.begin(), b.end()) != b.end())
        return false;
    return is_sorted(a.begin(), a.end());
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << isInorderTraversal(a) << "\n";
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
