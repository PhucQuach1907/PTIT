#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main() {
  int n, b, k, x, res, dark = 0;
  cin >> n >> k >> b;
  int len[n + 1];
  memset(len, 1, sizeof(len));
  for (int i = 0; i < b; i++) 
  {
    cin >> x;
    len[x] = 0;
  }
  for (int i = 1; i <= k; i++)
    dark += (!len[i] ? 1 : 0);
  res = dark;
  for (int i = k + 1; i <= n; i++) 
  {
    dark -= (!len[i - k] ? 1 : 0);
    dark += (!len[i] ? 1 : 0);
    res = min(res, dark);
  }
  cout << res;
  return 0;
}