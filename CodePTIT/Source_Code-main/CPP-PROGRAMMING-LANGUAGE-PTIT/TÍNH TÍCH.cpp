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
    int n, m;
    cin >> n >> m;
    vector < i64 > a(n), b(m);
    for (auto & c: a)
      cin >> c;
    for (auto & c: b)
      cin >> c;
    i64 ans = ( * max_element(a.begin(), a.end())) * ( * min_element(b.begin(), b.end()));
    cout << ans << "\n";
  }
  return 0;
}