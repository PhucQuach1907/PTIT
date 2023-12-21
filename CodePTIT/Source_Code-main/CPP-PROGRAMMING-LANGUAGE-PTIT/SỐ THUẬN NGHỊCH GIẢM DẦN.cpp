#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool isPalidromeString (string s)
{
  string tg=s;
  reverse(s.begin(),s.end());
  return (tg==s);
}
bool cmp (pair<string,int> a, pair<string,int> b)
{
  if (a.first.size()!=b.first.size())
    return a.first.size()>b.first.size();
  return a.first > b.first;
}
int main() 
{
  vector<string> a;
  string s;
  while (cin >> s)
  {
    if (isPalidromeString(s) && s.size()>1)
    {
      a.push_back(s);
    }
  }
  set<string> diff;
  unordered_map<string,int> cnt;
  vector<pair<string,int>> v;
  for (int i=0; i<a.size(); i++)
  {
    diff.insert(a[i]);
    cnt[a[i]]++;
  }
  for (string x:diff)
    v.push_back({x,cnt[x]});
  sort(v.begin(),v.end(),cmp);
  for (int i=0; i<v.size(); i++)
    cout << v[i].first << " " << v[i].second << "\n";
  return 0;
}