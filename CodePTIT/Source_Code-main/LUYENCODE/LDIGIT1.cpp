#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int base[10] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int Last_Digit(int n)
{
    if (n < 10)
        return base[n];
    string s = to_string(n);
    int last = s[s.size() - 2] - '0';
    if (last & 1)
        return (4 * Last_Digit(n / 5) * Last_Digit(s.back() - '0')) % 10;
    return (6 * Last_Digit(n / 5) * Last_Digit(s.back() - '0')) % 10;
}
int main()
{
    int n;
    cin >> n;
    cout << Last_Digit(n);
    return 0;
}
