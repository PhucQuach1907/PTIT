#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};
Node *makeNode(int d)
{
    Node *x = new Node;
    x->data = d;
    x->pLeft = x->pRight = NULL;
    return x;
}
Node *buildTree(vector<int> a, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = makeNode(a[mid]);
    root->pLeft = buildTree(a, start, mid - 1);
    root->pRight = buildTree(a, mid + 1, end);
    return root;
}
void postOrderTraversal(Node *Tree)
{
    if (!Tree)
        return;
    postOrderTraversal(Tree->pLeft);
    postOrderTraversal(Tree->pRight);
    cout << Tree->data << " ";
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    Node *Tree = buildTree(a, 0, n - 1);
    postOrderTraversal(Tree);
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
