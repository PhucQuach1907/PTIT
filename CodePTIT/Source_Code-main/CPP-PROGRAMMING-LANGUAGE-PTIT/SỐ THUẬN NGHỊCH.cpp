#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s,t;
    cin >> s;
    t=s;
    reverse(s.begin(),s.end());
    cout << (t==s?"YES\n":"NO\n");
  }
  return 0;
}