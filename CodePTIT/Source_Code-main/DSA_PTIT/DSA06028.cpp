#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Output(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        int val = a[i], pos = i;
        for (int j = i + 1; j < n; j++)
        {
            {
                if (a[j] < val)
                {
                    val = a[j];
                    pos = j;
                }
            }
        }
        swap(a[i], a[pos]);
        ans.push_back(a);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("Buoc %d: ", i + 1);
        Output(ans[i]);
    }
    return 0;
}
