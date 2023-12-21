#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
struct PERSON
{
    string name;
    int day, month, year;
};
typedef struct PERSON Person;
bool cmp(Person a, Person b)
{
    if (a.year != b.year)
        return a.year < b.year;
    if (a.month != b.month)
        return a.month < b.month;
    return a.day < b.day;
}
int main()
{
    int n;
    cin >> n;
    char c;
    Person a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].name >> a[i].day >> c >> a[i].month >> c >> a[i].year;
    sort(a, a + n, cmp);
    cout << a[n - 1].name << "\n" << a[0].name;
    return 0;
}