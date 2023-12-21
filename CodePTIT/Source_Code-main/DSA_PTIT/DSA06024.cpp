#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
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
        printf("Buoc %d: ", i + 1);
        for (int k = 0; k < n; k++)
            cout << a[k] << " \n"[k == n - 1];
    }
    return 0;
}
