#include <bits/stdc++.h>
using namespace std;
string Smallest(int m, int s)
{
    if (s > 9 * m || (m > 1 && s == 0))
        return "-1";
    string ans = "";
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            double tg = (s - j) * 1.0 / (m - i);
            if (i == 1 && tg <= 9 && j != 0)
            {
                ans += to_string(j);
                s -= j;
                break;
            }
            else if (tg <= 9 && i > 1)
            {
                ans += to_string(j);
                s -= j;
                break;
            }
        }
    }
    ans += to_string(s);
    return ans;
}
string Biggest(int m, int s)
{
    if (s > 9 * m || (m > 1 && s == 0))
        return "-1";
    string ans = "";
    for (int i = 1; i <= m; i++)
    {
        if (s >= 9)
        {
            ans += "9";
            s -= 9;
        }
        else if (s > 0 && s < 9)
        {
            ans += to_string(s);
            s -= s;
        }
        else
            ans += "0";
    }
    return ans;
}
int main()
{
    int m, s;
    cin >> m >> s;
    cout << Smallest(m, s) << " " << Biggest(m, s);
    return 0;
}
