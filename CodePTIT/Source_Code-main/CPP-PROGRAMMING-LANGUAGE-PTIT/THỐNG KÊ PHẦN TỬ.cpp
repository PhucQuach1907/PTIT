#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{
    int x;
    vector<int> diff;
    unordered_map<int, int> cnt;
    vector<int>::iterator it;
    while (cin >> x)
    {
        cnt[x]++;
        it = find(diff.begin(), diff.end(), x);
        if (it == diff.end())
            diff.push_back(x);
    }
    for (int i = 0; i < diff.size(); i++)
        cout << diff[i] << " " << cnt[diff[i]] << "\n";
    return 0;
}