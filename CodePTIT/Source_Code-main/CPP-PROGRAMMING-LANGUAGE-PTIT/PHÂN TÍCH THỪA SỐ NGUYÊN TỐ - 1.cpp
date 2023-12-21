#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0;
        cin >> n;
        while (n % 2 == 0)
        {
            n /= 2;
            count++;
        }
        if (count)
            cout << 2 << " " << count << " ";
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            if (count)
                cout << i << " " << count << " ";
        }
        if (n > 2)
            cout << n << " " << 1;
        cout << "\n";
    }
    return 0;
}
