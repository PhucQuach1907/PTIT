#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    s = "-" + s;
    vector<vector<bool>> isPalindrome(n + 1, vector<bool>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        isPalindrome[i][i] = 1;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
            isPalindrome[i][j] = (i + 1 == j ? s[i] == s[j] : s[i] == s[j] & isPalindrome[i + 1][j - 1]);
    }
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (isPalindrome[j][i])
                dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[n];
    return 0;
}
//isPalindrome[i][j]: true nếu s[i...j] là xâu đối xứng, ngược lại là false;
//dp[i]:số xâu đối xứng ít nhất được chia từ [1...i];
