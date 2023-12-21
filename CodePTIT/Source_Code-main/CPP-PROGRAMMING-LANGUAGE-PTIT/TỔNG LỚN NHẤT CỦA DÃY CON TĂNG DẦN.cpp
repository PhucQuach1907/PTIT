#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main() 
{
  long long t;
  cin >> t;
  while (t--)
  {
    long long n,i,j,ans=0;
    cin >> n;
    long long a[n],sum[n];
    for (i=0; i<n; i++)
    {
      cin >> a[i];
      sum[i]=a[i];
    }
    for (i=1; i<n; i++)
    {
      for (j=0; j<i; j++)
      {
        if (a[i]>a[j] && sum[i]<sum[j]+a[i])
          sum[i]=sum[j]+a[i];
      }
    }
    for (i=0; i<n; i++)
      ans=max(ans,sum[i]);
    cout << ans << "\n";
  }
  return 0;
}