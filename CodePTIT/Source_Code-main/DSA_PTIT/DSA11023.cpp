#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int preIdx;
int depth;
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
Node *buildTree(vector<int> inorder, vector<int> preorder, unordered_map<int, int> m, int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;
    int tmp = preorder[preIdx++];
    Node *root = makeNode(tmp);
    if (inStart == inEnd)
        return root;
    int inMid = m[tmp];
    root->pLeft = buildTree(inorder, preorder, m, inStart, inMid - 1);
    root->pRight = buildTree(inorder, preorder, m, inMid + 1, inEnd);
    return root;
}
void Find_Depth(Node *Tree, int tmp)
{
    if (!Tree)
        return;
    if (!Tree->pLeft && !Tree->pRight)
        depth = max(depth, tmp);
    Find_Depth(Tree->pLeft, tmp + 1);
    Find_Depth(Tree->pRight, tmp + 1);
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> preorder(n);
    for (auto &x : preorder)
        cin >> x;
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[inorder[i]] = i;
    preIdx = 0;
    Node *Tree = buildTree(inorder, preorder, m, 0, n - 1);
    depth = -1;
    Find_Depth(Tree, 0);
    cout << depth << "\n";
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
