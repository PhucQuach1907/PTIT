#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
const int MAX=1e5+5;
int Sum_Digits (int n)
{
  int res=0;
  while (n)
  {
    res+=(n%10);
    n/=10;
  }
  return res;
}
int Sum_Digits_Divisor (int n)
{
  int res=0;
  while (n%2==0)
  {
    n/=2;
    res+=2;
  }
  for (int i=3; i<=sqrt(n); i+=2)
  {
    while (n%i==0)
    {
      n/=i;
      res+=Sum_Digits(i);
    }
  }
  res+=(n>2?Sum_Digits(n):0);
  return res;
}
int main() 
{
  int Prime[MAX];
  memset(Prime,1,sizeof(Prime));
  Prime[0]=Prime[1]=0;
  for (int i=2; i<=MAX/2; i++)
  {
    if (Prime[i])
    {
      for (int j=2*i; j<MAX; j+=i)
        Prime[j]=0;
    }
  }
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << (!Prime[n] && Sum_Digits(n)==Sum_Digits_Divisor(n)?"YES":"NO") << "\n";
  }
  return 0;
}