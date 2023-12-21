#include <bits/stdc++.h>
using namespace std;
int isSphenic(int n)
{
    vector<int> a;
    set<int> b;
    while (n % 2 == 0)
    {
        n /= 2;
        a.push_back(2);
        b.insert(2);
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            a.push_back(i);
            b.insert(i);
        }
    }
    if (n > 2)
    {
        a.push_back(n);
        b.insert(n);
    }
    return (a.size() != b.size() || b.size() != 3 ? 0 : 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << isSphenic(n) << "\n";
    }
    return 0;
}