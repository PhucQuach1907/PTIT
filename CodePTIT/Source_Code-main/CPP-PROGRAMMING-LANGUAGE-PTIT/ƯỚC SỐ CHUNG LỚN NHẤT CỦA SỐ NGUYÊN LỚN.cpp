#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ui64 a,reduce=0;
    string b;
    cin >> a >> b;
    for (int i=0; i<b.size(); i++)
      reduce=(reduce*10+(b[i]-'0'))%a;
    cout << __gcd(a,reduce) << "\n";
  }
  return 0;
}
