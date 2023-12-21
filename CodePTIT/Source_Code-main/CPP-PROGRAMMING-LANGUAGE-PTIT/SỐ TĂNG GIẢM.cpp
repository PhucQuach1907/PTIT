#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{
    int a[10] = {5, 20, 38, 50, 38, 20, 8, 5, 0};
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << a[n - 1] << "\n";
    }
    return 0;
}