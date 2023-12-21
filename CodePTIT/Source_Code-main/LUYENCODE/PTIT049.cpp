#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
string Multiply(string s1, string s2)
{
    string ans = "";
    if (s1 == "0" || s2 == "0")
        return "0";
    if (s1.size() < s2.size())
        swap(s1, s2);
    int len = s1.size() + s2.size();
    vector<int> res(len, 0);
    int shift = len - 1;
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        int num2 = s2[i] - '0', index = shift, remain = 0;
        for (int j = s1.size() - 1; j >= 0; j--)
        {
            int num1 = s1[j] - '0';
            int tmp = res[index] + num2 * num1 + remain;
            res[index] = tmp % 10;
            remain = tmp / 10;
            index--;
        }
        res[index] = remain;
        shift--;
    }
    while (res[0] == 0)
        res.erase(res.begin());
    for (int i = 0; i < res.size(); i++)
        ans += to_string(res[i]);
    return ans;
}
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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll>> a;
    for (ll i = 1; i <= sqrt(k); i++)
    {
        if (k % i == 0)
        {
            ll div1 = i, div2 = k / i;
            if (div1 != div2)
            {
                if (div1 <= n && div2 <= m)
                    a.push_back({div1, div2});
                if (div2 <= n && div1 <= m)
                    a.push_back({div2, div1});
            }
            else
            {
                if (div1 <= n && div2 <= m)
                    a.push_back({div1, div2});
            }
        }
    }
    string ans = "0";
    for (auto x : a)
    {
        string p = to_string(n - x.first + 1);
        string q = to_string(m - x.second + 1);
        string mul = Multiply(p, q);
        ans = Sum(ans, mul);
    }
    cout << ans;
    return 0;
}
