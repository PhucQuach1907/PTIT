#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i & 1)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.rbegin(), even.rend());
    int i = 0, j = 0;
    for (int idx = 1; idx <= n; idx++)
        cout << (idx & 1 ? odd[i++] : even[j++]) << " ";
    return 0;
}
