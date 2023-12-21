#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
int main()
{
    ll s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    double m1 = sqrt(s1), m2 = sqrt(s3);
    double tmp1 = m1 / m2, tmp2 = sqrt(s2);
    double z = tmp1 * tmp2;
    double x = s2 / z;
    double y = s3 / x;
    double sum = 4 * (x + y + z);
    double MOD = 1000000007;
    double ans = fmod(sum, MOD);
    cout << fixed << setprecision(0) << ans;
    return 0;
}
