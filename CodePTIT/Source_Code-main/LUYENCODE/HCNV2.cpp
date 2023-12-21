#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Point
{
    ll x, y;
};
struct Rectangle
{
    Point A, B;
};
int main()
{
    Rectangle R1;
    cin >> R1.A.x >> R1.A.y >> R1.B.x >> R1.B.y;
    Rectangle R2;
    cin >> R2.A.x >> R2.A.y >> R2.B.x >> R2.B.y;
    ll w = min(max(R1.A.x, R1.B.x), max(R2.A.x, R2.B.x)) - max(min(R1.A.x, R1.B.x), min(R2.A.x, R2.B.x));
    ll h = min(max(R1.A.y, R1.B.y), max(R2.A.y, R2.B.y)) - max(min(R1.A.y, R1.B.y), min(R2.A.y, R2.B.y));
    cout << (w > 0 && h > 0 ? w * h : 0);
    return 0;
}
