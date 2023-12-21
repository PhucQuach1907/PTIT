#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string n;
    ui64 m, ans=0;
    cin >> n >> m;
    for (int i=0; i<n.size(); i++)
      ans=(ans*10+(n[i]-'0'))%m;
    cout << ans << "\n";
  }
  return 0;
}
