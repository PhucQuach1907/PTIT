#include <bits/stdc++.h>
using namespace std;
int n, start, path[100];
vector<vector<int>> hamiltion_circuit, hamilton_path;
void DFS(vector<vector<int>> a, vector<bool> &vis, int cur, int idx)
{
    path[idx] = cur;
    vis[cur] = true;
    if (idx == n)
    {
        if (a[cur][start])
        {
            vector<int> tmp(path + 1, path + 1 + idx);
            tmp.push_back(start);
            hamiltion_circuit.push_back(tmp);
        }
        else
        {
            vector<int> tmp(path + 1, path + 1 + idx);
            hamilton_path.push_back(tmp);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && a[cur][i])
            DFS(a, vis, i, idx + 1);
    }
    vis[cur] = false;
}
void Print_Path(vector<int> v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i];
        if (i != (int)v.size() - 1)
            cout << " -> ";
    }
    cout << "\n";
}
int main()
{
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    cout << "Nhap ma tran ke cua do thi:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        vector<bool> vis(n + 5, false);
        start = i;
        DFS(a, vis, i, 1);
    }
    if (hamilton_path.size() == 0 && hamiltion_circuit.size() == 0)
    {
        cout << "KHONG TON TAI DUONG DI HOAC CHU TRINH HAMILTION!";
        return 0;
    }
    cout << "SO LUONG DUONG DI HAMILTION: " << hamilton_path.size() << "\n";
    if (hamilton_path.size() > 0)
    {
        cout << "CAC DUONG DI HAMILTION:\n";
        for (auto x : hamilton_path)
            Print_Path(x);
    }
    cout << "\nSO LUONG CHU TRINH HAMILTION: " << hamiltion_circuit.size() << "\n";
    if (hamiltion_circuit.size() > 0)
    {
        cout << "CAC CHU TRINH HAMILTION:\n";
        for (auto x : hamiltion_circuit)
            Print_Path(x);
    }
    return 0;
}
