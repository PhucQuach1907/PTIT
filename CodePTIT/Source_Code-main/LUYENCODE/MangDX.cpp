#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            int l = i - 1, r = i + 2;
            while (l >= 0 && r < n && a[l] == a[r])
                l--, r++;
            ans = max(ans, r - l - 1);
        }
        if (a[i] == a[i + 2])
        {
            int l = i - 1, r = i + 3;
            while (l >= 0 && r < n && a[l] == a[r])
                l--, r++;
            ans = max(ans, r - l - 1);
        }
    }
    cout << ans;
    return 0;
}
