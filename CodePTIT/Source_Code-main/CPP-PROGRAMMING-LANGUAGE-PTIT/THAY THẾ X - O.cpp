#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int n, m;
char s[25][25];
void Trace(char s[25][25], int row, int col)
{
    if (row > n || row < 1 || col > m || col < 1)
        return;
    if (s[row][col] == 'O')
    {
        s[row][col] = 'V';
        Trace(s, row - 1, col);
        Trace(s, row, col + 1);
        Trace(s, row + 1, col);
        Trace(s, row, col - 1);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin.ignore();
        for (int i = 1; i <= n; i++)
        {
            string str;
            int index = 1;
            getline(cin, str);
            for (int j = 0; j < str.size(); j += 2)
                s[i][index++] = str[j];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1 || i == n || j == 1 || j == m)
                    Trace(s, i, j);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i][j] == 'V')
                    cout << "O ";
                else
                    cout << "X ";
            }
            cout << "\n";
        }
    }
    return 0;
}