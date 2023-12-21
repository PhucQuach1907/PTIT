#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> tmp(n);
    tmp[0] = 1;
    for (int i = 1; i < n; i++)
        tmp[i] = (s[i] == s[i - 1] ? tmp[i - 1] + 1 : 1);
    tmp.push_back(1);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (tmp[i] > 1 && tmp[i + 1] == 1 ? tmp[i] / 2 : 0);
    cout << sum;
    return 0;
}
