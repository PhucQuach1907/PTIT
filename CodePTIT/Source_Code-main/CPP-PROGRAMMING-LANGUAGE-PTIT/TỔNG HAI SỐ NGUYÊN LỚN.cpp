#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
string Sum(string x, string y)
{
    string ans;
    if (x.size() < y.size())
        swap(x, y);
    y.insert(0, x.size() - y.size(), '0');
    int a[x.size()], b[y.size()], sum[x.size()];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < x.size(); i++)
        a[i] = x[i] - '0';
    for (int i = 0; i < y.size(); i++)
        b[i] = y[i] - '0';
    int remain = 0;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int tmp = a[i] + b[i] + remain;
        sum[i] = (i == 0 ? tmp : tmp % 10);
        remain = tmp / 10;
    }
    for (int i = 0; i < x.size(); i++)
        ans += to_string(sum[i]);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        cout << Sum(x, y) << "\n";
    }
    return 0;
}