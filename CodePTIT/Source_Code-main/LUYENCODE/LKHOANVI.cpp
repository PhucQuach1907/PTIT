#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    do
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}
