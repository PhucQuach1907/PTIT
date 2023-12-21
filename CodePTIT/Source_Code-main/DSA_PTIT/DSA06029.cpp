#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Output(multiset<int> a)
{
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<multiset<int>> ans;
    multiset<int> m;
    for (int i = 0; i < n; i++)
    {
        m.insert(a[i]);
        ans.push_back(m);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("Buoc %d: ", i);
        Output(ans[i]);
    }
    return 0;
}
