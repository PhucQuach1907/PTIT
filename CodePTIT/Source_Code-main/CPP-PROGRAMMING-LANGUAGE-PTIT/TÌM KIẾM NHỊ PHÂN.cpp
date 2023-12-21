#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int t;
  cin >> t;
  while (t--) 
  {
    int n, x;
    cin >> n >> x;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    int exist = binary_search(a.begin(), a.end(), x);
    cout << (exist == 1 ? 1 : -1) << "\n";
  }
  return 0;
}