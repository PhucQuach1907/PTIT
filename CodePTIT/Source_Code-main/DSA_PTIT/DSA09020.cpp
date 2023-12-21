#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        char *str = new char[s.size() + 1];
        strcpy(str, s.c_str());
        char *p = strtok(str, " \t\n");
        while (p != NULL)
        {
            int j = stoi(p);
            adj[i][j] = adj[j][i] = 1;
            p = strtok(NULL, " \t\n");
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j] << " \n"[j == n];
    }
    return 0;
}
