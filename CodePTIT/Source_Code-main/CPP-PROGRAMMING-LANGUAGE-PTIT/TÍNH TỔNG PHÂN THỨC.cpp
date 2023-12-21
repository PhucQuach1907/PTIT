#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main() 
{
  int n;
  cin >> n;
  double ans=0;
  for (int i=1; i<=n; i++)
  ans+=(1.0/i);
  cout << fixed << setprecision(4) << ans << "\n";
  return 0;
}