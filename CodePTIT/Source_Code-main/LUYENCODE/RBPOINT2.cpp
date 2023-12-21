#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> b(n), r(n);
    for (auto &x : b)
        cin >> x;
    for (auto &x : r)
        cin >> x;
    sort(b.begin(), b.end());
    sort(r.begin(), r.end());
    int i = 0, j = 0, mindist = INT_MAX;
    while (i < n && j < n)
    {
        mindist = min(mindist, abs(b[i] - r[j]));
        if (b[i] == r[j])
            i++, j++;
        else if (b[i] < r[j])
            i++;
        else
            j++;
    }
    cout << mindist;
    return 0;
}
