#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool Compare_Two_Large_Numbers(string a, string b)
{
    if (a.size() > b.size())
        return 1;
    if (a.size() == b.size() && a >= b)
        return 1;
    return 0;
}
string Multiply(string s1, string s2)
{
    string ans = "";
    if (s1 == "0" || s2 == "0")
        return "0";
    while (s1[0] == '0')
        s1.erase(0, 1);
    while (s2[0] == '0')
        s2.erase(0, 1);
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
int Divide(string s1, string s2)
{
    int num;
    for (int i = 1; i <= 10; i++)
    {
        string mul = Multiply(s2, to_string(i));
        if (mul == s1)
        {
            num = i;
            break;
        }
        else if (Compare_Two_Large_Numbers(mul, s1))
        {
            num = i - 1;
            break;
        }
    }
    return num;
}
string Subtract(string x, string y)
{
    string ans;
    if (x.size() < y.size())
        swap(x, y);
    y.insert(0, x.size() - y.size(), '0');
    if (x < y)
        swap(x, y);
    vector<int> a(x.size()), b(y.size()), sub(x.size());
    for (int i = 0; i < x.size(); i++)
        a[i] = x[i] - '0';
    for (int i = 0; i < y.size(); i++)
        b[i] = y[i] - '0';
    int remain = 0;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int tmp = a[i] - b[i] - remain;
        remain = (tmp < 0 ? 1 : 0);
        sub[i] = (tmp + 10) % 10;
    }
    while (sub[0] == 0)
        sub.erase(sub.begin());
    for (int i = 0; i < sub.size(); i++)
        ans += to_string(sub[i]);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2, tg = "";
        cin >> s1 >> s2;
        vector<int> res;
        if (s1 == "0" || (s1 != s2 && !Compare_Two_Large_Numbers(s1, s2)))
        {
            cout << "0\n";
            continue;
        }
        int start;
        for (int i = 0; i < s1.size(); i++)
        {
            tg += s1[i];
            if (Compare_Two_Large_Numbers(tg, s2))
            {
                int num = Divide(tg, s2);
                res.push_back(num);
                string mul = Multiply(s2, to_string(num));
                if (mul == tg)
                    tg = "";
                else
                    tg = Subtract(tg, mul);
                start = i + 1;
                break;
            }
        }
        for (int i = start; i < s1.size(); i++)
        {
            tg += s1[i];
            int num = Divide(tg, s2);
            res.push_back(num);
            string mul = Multiply(s2, to_string(num));
            if (mul == tg)
                tg = "";
            else
                tg = Subtract(tg, mul);
        }
        for (auto c : res)
            cout << c;
        cout << "\n";
    }
    return 0;
}