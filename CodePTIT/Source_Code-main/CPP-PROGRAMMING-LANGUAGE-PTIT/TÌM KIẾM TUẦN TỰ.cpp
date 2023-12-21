#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int t;
  cin >> t;
  while (t--) 
  {
    int n, x, ok = 0, index;
    cin >> n >> x;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++) 
    {
      if (a[i] == x) 
      {
        index = i + 1;
        ok = 1;
        break;
      }
    }
    cout << (ok == 1 ? index : -1) << "\n";
  }
  return 0;
}