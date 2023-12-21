#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, res = 0;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            count[a[i]]++;
        }
        int l = *min_element(a.begin(), a.end()), r = *max_element(a.begin(), a.end());
        for (int i = l; i <= r; i++)
            res += (count[i] == 0 ? 1 : 0);
        cout << res << "\n";
    }
    return 0;
}
