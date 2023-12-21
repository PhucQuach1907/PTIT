#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main() 
{
  int t;
  cin >> t;
  while (t--) 
  {
    int n, m;
    cin >> n >> m;
    int a[n][m], res[n][m];
    bool vis[n][m];
    memset(vis,0,sizeof(vis));
    vector<int> v;
    for (int i = 0; i < n; i++) 
    {
      for (int j = 0; j < m; j++)
      {
        cin >> a[i][j];
        res[i][j]=a[i][j];
      }
    }
    if (n==1 || m==1)
    {
      for (int i=0; i<n; i++)
      {
        for (int j=0; j<m; j++)
          v.push_back(a[i][j]);
      }
      rotate(v.begin(),v.begin()+(v.size()-1),v.end());
      for (int x:v)
        cout << x << " ";
      cout << "\n";
      continue;
    }
    int row=n-1, col=m-1, d=0, size=m*n, cnt=0;
    while (1)
    {
      if (vis[d+1][d])
      {
        for (int i=d; i<=col; i++)
          v.push_back(a[d][i]);
        break;
      }
      res[d][d]=a[d+1][d], vis[d][d]=1, cnt++;
      for (int i=d+1; i<=col; i++)
      {
        res[d][i]=a[d][i-1];
        vis[d][i]=1;
        cnt++;
      }
      for (int i=d+1; i<=row; i++)
      {
        res[i][col]=a[i-1][col];
        vis[i][col]=1;
        cnt++;
      }
      for (int i=col-1; i>=d; i--)
      {
        res[row][i]=a[row][i+1];
        vis[row][i]=1;
        cnt++;
      }
      for (int i=row-1; i>d; i--)
      {
        res[i][d]=a[i+1][d];
        vis[i][d]=1;
        cnt++;
      }
      if (cnt==size)
        break;
      d++, row--, col--;
    }
    if (v.size()!=0)
    {
      rotate(v.begin(),v.begin()+(v.size()-1),v.end());
    }
    int pos=0;
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<m; j++)
      {
        if (!vis[i][j])
          res[i][j]=v[pos++];
      }
    }
    for (int i=0; i<n; i++)
    {
      for (int j=0; j<m; j++)
        cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}