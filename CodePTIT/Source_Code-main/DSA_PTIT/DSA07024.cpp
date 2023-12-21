#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for (auto &c : a)
        cin >> c;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(i);
        else
        {
            while (!st.empty() && a[i] < a[st.top()])
            {
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        r[st.top()] = n;
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            st.push(i);
        else
        {
            while (!st.empty() && a[i] < a[st.top()])
            {
                l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        l[st.top()] = -1;
        st.pop();
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = min(a[i], r[i] - l[i] - 1);
        if (temp == a[i])
            res = max(res, temp);
    }
    cout << res << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
