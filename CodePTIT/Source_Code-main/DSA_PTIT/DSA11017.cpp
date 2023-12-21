#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int idx;
void Print_PostOrder(vector<int> inorder, vector<int> preorder, int start, int end, map<int, int> pos)
{
    if (start > end)
        return;
    int mid = pos[preorder[idx++]];
    Print_PostOrder(inorder, preorder, start, mid - 1, pos);
    Print_PostOrder(inorder, preorder, mid + 1, end, pos);
    cout << inorder[mid] << " ";
}
void Solve()
{
    idx = 0;
    int n;
    cin >> n;
    vector<int> preorder(n);
    for (auto &x : preorder)
        cin >> x;
    vector<int> inorder(preorder.begin(), preorder.end());
    sort(inorder.begin(), inorder.end());
    map<int, int> pos;
    for (int i = 0; i < n; i++)
        pos[inorder[i]] = i;
    Print_PostOrder(inorder, preorder, 0, n - 1, pos);
    cout << "\n";
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
