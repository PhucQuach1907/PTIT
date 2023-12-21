#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<long long> a(n);
    set<long long> s;
    set<long long>::iterator it;
    for (long long i=0; i<n; i++)
    {
      cin >> a[i];
      s.insert(a[i]);
    }
    for (long long i=0; i<n; i++)
    {
      it=s.find(i);
      cout << (it!=s.end()?i:-1) << " ";
    }
    cout << "\n";
  }
  return 0;
}