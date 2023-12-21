#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long;
const double PI = 2 * acos(0);
const int MOD = 1e9 + 7;
int main()
{
    int Prime[35];
    memset(Prime, 0, sizeof(Prime));
    Prime[2] = 1, Prime[3] = 1, Prime[5] = 1, Prime[7] = 1, Prime[13] = 1, Prime[17] = 1, Prime[19] = 1, Prime[31] = 1;
    vector<long long> Perfect_Number;
    for (long long i = 2; i <= 31; i++)
    {
        if (Prime[i])
            Perfect_Number.push_back(pow(2, i - 1) * (pow(2, i) - 1));
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << binary_search(Perfect_Number.begin(), Perfect_Number.end(), n) << "\n";
    }
    return 0;
}