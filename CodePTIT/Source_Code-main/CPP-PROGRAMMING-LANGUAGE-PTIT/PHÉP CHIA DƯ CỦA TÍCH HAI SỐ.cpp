#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long a,b,c,ans=0;
    cin >> a >> b >> c;
    while (b)
    {
      if (b%2) 
        ans=(ans+a)%c;
      b/=2;
      a=(a+a)%c;
    }
    cout << ans << "\n";
  }
  return 0;
}