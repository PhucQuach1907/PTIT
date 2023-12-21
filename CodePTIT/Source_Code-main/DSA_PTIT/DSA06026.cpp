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
    int step = 1;
    while (!is_sorted(a.begin(), a.end()))
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
                swap(a[i], a[i - 1]);
        }
        printf("Buoc %d: ", step);
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        step++;
    }
    return 0;
}
