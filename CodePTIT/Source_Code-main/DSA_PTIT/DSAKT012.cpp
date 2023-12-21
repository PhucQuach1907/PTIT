#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long;
struct Data
{
    vector<int> v;
    int sum;
};
int main()
{
    int n, S;
    cin >> n >> S;
    vector<int> money(n);
    for (auto &x : money)
        cin >> x;
    sort(money.begin(), money.end());
    unordered_set<int> diff;
    queue<Data> q;
    q.push({money, 0});
    while (!q.empty())
    {
        Data tmp = q.front();
        q.pop();
        if (tmp.sum == S)
        {
            cout << (n - tmp.v.size());
            return 0;
        }
        vector<int> vv = tmp.v;
        for (int i = 0; i < (int)vv.size(); i++)
        {
            if (diff.find(tmp.sum + vv[i]) == diff.end() && tmp.sum + vv[i] <= S)
            {
                vector<int> arr = vv;
                arr.erase(arr.begin() + i);
                q.push({arr, tmp.sum + vv[i]});
                diff.insert(tmp.sum + vv[i]);
            }
        }
    }
    cout << -1;
    return 0;
}
