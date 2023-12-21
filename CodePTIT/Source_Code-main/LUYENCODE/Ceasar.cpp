#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    string s;
    int k;
    cin >> s >> k;
    char c = 'a';
    vector<char> key;
    for (int i = 0; i < 26; i++)
        key.push_back(c++);
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        int pos = s[i] - 97;
        pos = (pos - k + 26) % 26;
        res += key[pos];
    }
    cout << res;
    return 0;
}
