#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
const double PI = 2 * acos(0);
const int MOD = 1e9 + 7;
int Sum_Digits(string s)
{
    if (s.size() == 1)
        return s == "9";
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += (s[i] - '0');
    return Sum_Digits(to_string(sum));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << Sum_Digits(s) << "\n";
    }
    return 0;
}