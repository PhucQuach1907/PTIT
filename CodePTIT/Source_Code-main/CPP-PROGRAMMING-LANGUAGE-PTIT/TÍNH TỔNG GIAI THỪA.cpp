#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main() 
{
  ui64 a[25];
  a[1]=1;
  for (ui64 i=2; i<=20; i++)
    a[i]=a[i-1]*i;
  ui64 n, ans=0;
  cin >> n;
  for (int i=1; i<=n; i++)
    ans+=a[i];
  cout << ans;
  return 0;
}