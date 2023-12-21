#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int a[105][105];
void Change (int row, int col, int n, int m)
{
  for (int i=1; i<=n; i++)
    a[i][col]=1;
  for (int i=1; i<=m; i++)
    a[row][i]=1;
}
int main() 
{
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=m; j++)
        cin >> a[i][j];
    }
    for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=m; j++)
      {
        if (a[i][j])
          v.push_back({i,j});
      }
    }
    for (int i=0; i<v.size(); i++)
      Change(v[i].first,v[i].second,n,m);
    for (int i=1; i<=n; i++)
    {
      for (int j=1; j<=m; j++)
        cout << a[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}