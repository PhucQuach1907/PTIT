#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Point
{
    double x, y, z;
};
Point Mul(Point a, Point b)
{
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
double Size(Point a)
{
    return hypot(a.x, a.y, a.z);
}
void Solve()
{
    Point A, B, C;
    cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;
    Point AB = {B.x - A.x, B.y - A.y, B.z - A.z};
    Point BC = {C.x - B.x, C.y - B.y, C.z - B.z};
    Point up = Mul(AB, BC);
    double ans = Size(up) / Size(BC);
    cout << fixed << setprecision(2) << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
