#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Output(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
                swap(a[i], a[j]);
        }
        ans.push_back(a);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("Buoc %d: ", i + 1);
        Output(ans[i]);
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
