#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
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
    string a;
    ui64 b,M, reduce=0;
    cin >> a >> b >> M;
    for (int i=0; i<a.size(); i++)
      reduce=(reduce*10+(a[i]-'0'))%M;
    cout << Exp(reduce,b,M) << "\n";
  }
  return 0;
}
