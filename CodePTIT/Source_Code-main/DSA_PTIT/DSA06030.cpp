#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Output(vector<int> a)
{
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        vector<vector<int>> ans;
        while (!is_sorted(a.begin(), a.end()))
        {
            for (int i = 1; i < n; i++)
            {
                if (a[i] < a[i - 1])
                    swap(a[i], a[i - 1]);
            }
            ans.push_back(a);
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            printf("Buoc %d: ", i + 1);
            Output(ans[i]);
        }
    }
    return 0;
}
