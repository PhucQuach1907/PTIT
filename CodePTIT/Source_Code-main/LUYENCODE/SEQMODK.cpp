#include <bits/stdc++.h>
#define maxn 1009
using namespace std;
int n, a[maxn], k, L[maxn][maxn];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    L[0][0] = 0;
    for (int i = 1; i <= k - 1; i++) L[0][i] = -1e9;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i] % k;
        for (int j = 0; j <= k - 1; j++) L[i][j] = max(L[i - 1][j], L[i - 1][(j - a[i] + k) % k] + 1);
    }
    cout << L[n][0];
}
