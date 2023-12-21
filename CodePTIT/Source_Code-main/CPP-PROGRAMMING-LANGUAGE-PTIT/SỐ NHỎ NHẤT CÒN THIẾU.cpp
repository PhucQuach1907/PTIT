#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main() 
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    unordered_map<int,int> count;
    vector<int> a(n-1);
    for (auto &c : a)
    {
      cin >> c;
      count[c]++;
    }
    for (int i=1; i<=n; i++)
    {
      if (count[i]==0)
      {
        cout << i << "\n";
        break;
      }
    }
  }
  return 0;
}