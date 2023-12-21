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
    multiset<int> m;
    for (int i = 0; i < n; i++)
    {
        m.insert(a[i]);
        printf("Buoc %d: ", i);
        for (auto x : m)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
