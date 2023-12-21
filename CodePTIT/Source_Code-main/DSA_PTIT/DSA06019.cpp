#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct ELE
{
    int val;
    int fre;
};
typedef struct ELE Ele;
bool cmp(Ele x, Ele y)
{
    if (x.fre != y.fre)
        return x.fre > y.fre;
    if (x.fre == y.fre && x.val != y.val)
        return x.val < y.val;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, len = 0;
        cin >> n;
        vector<int> a(n);
        set<int> s;
        unordered_map<int, int> count;
        Ele v[n];
        for (auto &c : a)
        {
            cin >> c;
            s.insert(c);
            count[c]++;
        }
        set<int>::iterator itr;
        for (itr = s.begin(); itr != s.end(); itr++)
        {
            v[len].val = *itr;
            v[len].fre = count[*itr];
            len++;
        }
        sort(v, v + len, cmp);
        for (int i = 0; i < len; i++)
        {
            for (int j = 1; j <= v[i].fre; j++)
                cout << v[i].val << " ";
        }
        cout << "\n";
    }
    return 0;
}
