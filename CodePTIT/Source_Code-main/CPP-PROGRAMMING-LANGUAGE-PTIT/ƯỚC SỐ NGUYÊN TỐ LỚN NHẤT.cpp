#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        while (n % 2 == 0)
        {
            n /= 2;
            a.push_back(2);
        }
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                a.push_back(i);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 2)
            a.push_back(n);
        cout << *max_element(a.begin(), a.end()) << "\n";
    }
    return 0;
}
