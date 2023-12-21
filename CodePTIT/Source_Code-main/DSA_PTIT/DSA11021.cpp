#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int preIdx;
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
void Find_Leaf(Node *Tree, vector<int> &leaf)
{
    if (!Tree)
        return;
    if (!Tree->pLeft && !Tree->pRight)
        leaf.push_back(Tree->data);
    Find_Leaf(Tree->pLeft, leaf);
    Find_Leaf(Tree->pRight, leaf);
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
    vector<int> leaf;
    Find_Leaf(Tree, leaf);
    for (auto x : leaf)
        cout << x << " \n"[x == leaf.back()];
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
