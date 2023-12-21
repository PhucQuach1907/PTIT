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
    ui64 n;
    vector < ui64 > a(95);
    cin >> n;
    a[0] = 0, a[1] = 1;
    for (int i = 2; i <= n; i++)
      a[i] = a[i - 2] + a[i - 1];
    cout << a[n] << "\n";
  }
  return 0;
}