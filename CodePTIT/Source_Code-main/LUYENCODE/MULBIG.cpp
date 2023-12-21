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
int main()
{
    string a, b;
    cin >> a >> b;
    cout << Multiply(a, b);
    return 0;
}
