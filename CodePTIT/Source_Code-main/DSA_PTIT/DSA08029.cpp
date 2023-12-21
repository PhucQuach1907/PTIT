#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Data
{
    vector<vector<int>> arr;
    int count;
};
void Rotate_Right(vector<vector<int>> &a)
{
    int x = a[0][1], y = a[0][2], z = a[1][1], t = a[1][2];
    a[0][1] = z, a[0][2] = x, a[1][1] = t, a[1][2] = y;
}
void Rotate_Left(vector<vector<int>> &a)
{
    int x = a[0][0], y = a[0][1], z = a[1][0], t = a[1][1];
    a[0][0] = z, a[0][1] = x, a[1][0] = t, a[1][1] = y;
}
bool Check(vector<vector<int>> arr, vector<vector<int>> b)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}
void Solve()
{
    vector<vector<int>> a(2, vector<int>(3)), b(2, vector<int>(3));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> b[i][j];
    }
    queue<Data> q;
    Data m;
    m.arr = a;
    m.count = 0;
    q.push(m);
    while (!q.empty())
    {
        Data temp = q.front();
        q.pop();
        if (Check(temp.arr, b))
        {
            cout << temp.count << "\n";
            return;
        }
        Data m1 = temp, m2 = temp;
        Rotate_Left(m1.arr);
        Rotate_Right(m2.arr);
        m1.count = m2.count = temp.count + 1;
        q.push(m1);
        q.push(m2);
    }
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
