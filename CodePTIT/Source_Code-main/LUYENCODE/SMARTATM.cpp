#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int minCoins(int coins[], int m, int V)
{
    int table[V + 1];
    table[0] = 0;
    for (int i = 1; i <= V; i++)
        table[i] = INT_MAX;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < m; j++)
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
    }
    if (table[V] == INT_MAX)
        return -1;
    return table[V];
}
int main()
{
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << minCoins(a, n, s);
    return 0;
}
