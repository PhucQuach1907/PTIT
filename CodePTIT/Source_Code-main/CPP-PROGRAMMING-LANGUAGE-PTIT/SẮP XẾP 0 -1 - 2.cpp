#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int t;
  cin >> t;
  while (t--) 
  {
    int n, x;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.begin(), a.end());
    for (auto c: a)
      cout << c << " ";
    cout << "\n";
  }
  return 0;
}