#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Find(vector<int> parent, int x)
{
    if (parent[x] == -1)
        return x;
    return Find(parent, parent[x]);
}
void Union(vector<int> &parent, int x, int y)
{
    parent[x] = y;
}
int main()
{
    int V, E;
    cout << "Nhap so dinh cua do thi: ";
    cin >> V;
    cout << "Nhap so canh cua do thi: ";
    cin >> E;
    vector<pair<int, int>> Edge(E);
    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < E; i++)
        cin >> Edge[i].first >> Edge[i].second;
    vector<int> parent(V + 1, -1);
    for (int i = 0; i < E; i++)
    {
        int x = Find(parent, Edge[i].first);
        int y = Find(parent, Edge[i].second);
        if (x == y)
        {
            cout << "=> DO THI CO TON TAI CHU TRINH\n";
            return 0;
        }
        Union(parent, x, y);
    }
    cout << "=> DO THI KHONG TON TAI CHU TRINH\n";
    return 0;
}
