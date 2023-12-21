#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    multiset<int> s;
    for (auto &c:a) 
      cin >> c;
    for (int i=0; i<k; i++)
      s.insert(a[i]);
    cout << *s.rbegin() << " ";
    for (int i=k; i<n; i++)
    {
      s.erase(s.find(a[i-k]));
      s.insert(a[i]);
      cout << *s.rbegin() << " ";
    }
    cout << "\n";
  }
  return 0;
}