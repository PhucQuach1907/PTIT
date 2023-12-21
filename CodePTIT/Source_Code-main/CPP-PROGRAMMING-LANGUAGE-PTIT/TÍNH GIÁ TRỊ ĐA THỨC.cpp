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
    ui64 n,x,ans=0;
    cin >> n >> x;
    vector<ui64> a(n);
    for (auto &c:a)
      cin >> c;
    reverse(a.begin(),a.end());
    for (ui64 i=0; i<n; i++)
      ans=(ans+Mul(a[i],Exp(x,i,MOD),MOD))%MOD;
    cout << ans << "\n";
  }
  return 0;
}
