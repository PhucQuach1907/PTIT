#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define i64 long long
int main() 
{
  int t;
  cin >> t;
  while (t--) 
  {
    ui64 x, y, p, ans = 1;
    cin >> x >> y >> p;
    if (p == 1) 
    {
      cout << 0 << "\n";
      continue;
    }
    while (y) 
    {
      if (y & 1)
        ans = (ans * x) % p;
      y /= 2;
      x = (x * x) % p;
    }
    cout << ans << "\n";
  }
  return 0;
}