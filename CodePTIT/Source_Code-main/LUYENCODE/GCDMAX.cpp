#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int l, r;
    cin >> l >> r;
    int ans = 1;
    for (int i = r / 2; i >= 1; i--)
    {
        if (r / i - (l - 1) / i > 1)
        {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}
/*
Chạy i từ R/2 đến 1, nếu bội của i trong [L,R] > 1 thì kết quả là i
*/
