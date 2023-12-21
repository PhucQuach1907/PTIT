#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        char *str = new char[s.size() + 1];
        strcpy(str, s.c_str());
        char *p = strtok(str, " \t\n");
        while (p != NULL)
        {
            adj[i].push_back(stoi(p));
            p = strtok(NULL, " \t\n");
        }
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            if (!vis[i][x] && !vis[x][i])
            {
                cout << i << " " << x << "\n";
                vis[i][x] = vis[x][i] = true;
            }
        }
    }
    return 0;
}
