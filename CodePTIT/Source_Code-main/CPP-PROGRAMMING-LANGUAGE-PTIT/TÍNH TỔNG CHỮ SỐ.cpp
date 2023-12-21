#include <bits/stdc++.h>
using namespace std;
int One_Digit (int n)
{
  if (n < 10) return n;
  int sum=0;
  while (n)
  {
    sum+=(n%10);
    n/=10;
  }
  return One_Digit(sum);
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << One_Digit(n) << "\n";
  }
  return 0;
}