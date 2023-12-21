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
    int n, tmp;
    cin >> n;
    vector<int> a(n), v;
    for (auto &c:a)
      cin >> c;
    for (int i=0; i<n; i++)
    {
      if (i==0)
        tmp=a[i]*a[i+1];
      else if (i==n-1)
        tmp=a[i]*a[i-1];
      else
        tmp=a[i-1]*a[i+1];
      v.push_back(tmp); 
    }
    for (auto c:v)
      cout << c << " ";
    cout << "\n";
  }
  return 0;
}