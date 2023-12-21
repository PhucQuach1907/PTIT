#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
struct Time
{
    int hour, minute, second;
};
bool cmp(Time a, Time b)
{
    if (a.hour != b.hour)
        return a.hour < b.hour;
    if (a.minute != b.minute)
        return a.minute < b.minute;
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    vector<Time> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].hour >> a[i].minute >> a[i].second;
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << a[i].hour << " " << a[i].minute << " " << a[i].second << "\n";
    return 0;
}