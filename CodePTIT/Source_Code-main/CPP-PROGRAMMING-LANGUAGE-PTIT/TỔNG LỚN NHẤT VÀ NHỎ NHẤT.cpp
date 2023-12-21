#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
ui64 String_To_Number(string s)
{
    ui64 res = 0;
    for (int i = 0; i < s.size(); i++)
        res = res * 10 + (s[i] - '0');
    return res;
}
ui64 Min_Sum(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
        s1[i] = (s1[i] == '6' ? '5' : s1[i]);
    for (int i = 0; i < s2.size(); i++)
        s2[i] = (s2[i] == '6' ? '5' : s2[i]);
    return String_To_Number(s1) + String_To_Number(s2);
}
ui64 Max_Sum(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
        s1[i] = (s1[i] == '5' ? '6' : s1[i]);
    for (int i = 0; i < s2.size(); i++)
        s2[i] = (s2[i] == '5' ? '6' : s2[i]);
    return String_To_Number(s1) + String_To_Number(s2);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << Min_Sum(s1, s2) << " " << Max_Sum(s1, s2) << "\n";
    }
    return 0;
}