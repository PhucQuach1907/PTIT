#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), back, diff;
        vector<pair<int, int>> front;
        unordered_map<int, int> cfa, csa;
        for (auto &c : a)
        {
            cin >> c;
            cfa[c]++;
        }
        for (auto &c : b)
        {
            cin >> c;
            csa[c]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (csa[a[i]] == 0)
                back.push_back(a[i]);
        }
        sort(back.begin(), back.end());
        for (int i = 0; i < m; i++)
        {
            if (csa[b[i]] > 0)
                diff.push_back(b[i]);
            csa[b[i]] = 0;
        }
        for (int i = 0; i < diff.size(); i++)
        {
            for (int j = 1; j <= cfa[diff[i]]; j++)
                cout << diff[i] << " ";
        }
        for (int i = 0; i < back.size(); i++)
            cout << back[i] << " ";
        cout << "\n";
    }
    return 0;
}