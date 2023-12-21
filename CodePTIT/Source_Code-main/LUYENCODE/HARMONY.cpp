#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool isHarmony(vector<int> a, int n)
{
    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++)
        diff[i] = abs(a[i] - a[i + 1]);
    vector<int> b(n - 1);
    b[0] = (diff[0] == 1 ? 1 : 0);
    for (int i = 1; i < n - 1; i++)
        b[i] = (diff[i] != 1 ? 0 : b[i - 1] + 1);
    int max_len = -1;
    for (int i = 0; i < n - 1; i++)
        max_len = max(max_len, b[i]);
    int mid = n / 2;
    return (max_len > mid);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        cout << (isHarmony(a, n) ? "Yes\n" : "No\n");
    }
    return 0;
}
