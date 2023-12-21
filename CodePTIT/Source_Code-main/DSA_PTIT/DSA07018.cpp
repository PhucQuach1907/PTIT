#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
map<int, int, greater<int>> res;
void Split(string s)
{
    char *ss = new char[s.size() + 1];
    strcpy(ss, s.c_str());
    char *p = strtok(ss, " \t\n");
    vector<string> str;
    while (p != NULL)
    {
        str.push_back(p);
        p = strtok(NULL, " \t\n");
    }
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i].size() == 1)
            continue;
        res[stoi(str[i].substr(str[i].find('^') + 1))] += stoi(str[i].substr(0, str[i].find('*')));
    }
}
void Solve()
{
    res.clear();
    string s;
    getline(cin, s);
    Split(s);
    getline(cin, s);
    Split(s);
    string ans = "";
    for (auto x : res)
        ans += (to_string(x.second) + "*x^" + to_string(x.first) + " + ");
    while (!isdigit(ans.back()))
        ans.pop_back();
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        Solve();
    }
    return 0;
}
