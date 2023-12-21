#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main() 
{
  int t;
  cin >> t;
  while (t--)
  {
    int n,k,x,count=0;
    cin >> n;
    vector<int> a(n),v;
    for (auto &c:a)
      cin >> c;
    cin >> k >> x;
    int pos=lower_bound(a.begin(),a.end(),x)-a.begin();
    int l,r;
    l=r=pos;
    while (count<k)
    {
      if (l>=0)
      {
        v.push_back(a[--l]);
        count++;
      }
      if (r<n)
      {
        v.push_back(a[++r]);
        count++;
      }
    }
    sort(v.begin(),v.end());
    for (auto c:v)
      cout << c << " ";
    cout << "\n";
  }
  return 0;
}