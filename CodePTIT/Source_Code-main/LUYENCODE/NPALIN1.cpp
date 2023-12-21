#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    while (cin >> n)
    {
        if (n % 2 == 0)
            n--;
        cout << 9;
        for (int i = 1; i <= n / 2; i++)
            cout << 0;
        cout << "\n";
    }
    return 0;
}
