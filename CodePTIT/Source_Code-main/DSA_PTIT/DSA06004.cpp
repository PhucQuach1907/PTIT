#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e5 + 5;
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<int> uni(MAX), inter(MAX);
    auto it = set_union(a.begin(), a.end(), b.begin(), b.end(), uni.begin());
    uni.resize(it - uni.begin());
    auto itr = set_intersection(a.begin(), a.end(), b.begin(), b.end(), inter.begin());
    inter.resize(itr - inter.begin());
    for (int i = 0; i < uni.size(); i++)
        cout << uni[i] << " ";
    cout << "\n";
    for (int i = 0; i < inter.size(); i++)
        cout << inter[i] << " ";
    cout << "\n";
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
