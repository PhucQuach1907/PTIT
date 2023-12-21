#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
const ui64 MOD=1e9+7;
ui64 Mul (ui64 a, ui64 b, ui64 M)
{
  if (!b)
    return 0;
  ui64 ans=0;
  a%=M;
  while (b)
  {
    if (b&1)
      ans=(ans+a)%M;
    b/=2;
    a=(a+a)%M;
  }
  return ans;
}
ui64 Exp (ui64 a, ui64 b, ui64 M)
{
  ui64 ans=1;
  a%=M;
  while (b)
  {
    if (b&1)
      ans=Mul(ans,a,M)%M;
    b/=2;
    a=Mul(a,a,M)%M;
  }
  return ans;
}
int main() 
{
  int t;
  cin >> t;
  while (t--)
  {
    ui64 n,h=1,g;
    cin >> n;
    vector<ui64> a(n);
    for (auto &c:a)
    {
      cin >> c;
      h=(h*c)%MOD;
    }
    g=a[0];
    for (int i=1; i<n; i++)
      g=__gcd(g,a[i]);
    cout << Exp(h,g,MOD) << "\n";
  }
  return 0;
}