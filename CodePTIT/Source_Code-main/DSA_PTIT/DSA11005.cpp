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
Node *buildTree(vector<int> inorder, vector<int> levelorder, int start, int end, int n)
{
    if (n <= 0)
        return NULL;
    Node *Tree = makeNode(levelorder[0]);
    int mid;
    for (int i = start; i <= end; i++)
    {
        if (levelorder[0] == inorder[i])
        {
            mid = i;
            break;
        }
    }
    unordered_set<int> s;
    for (int i = start; i < mid; i++)
        s.insert(inorder[i]);
    vector<int> lLevel, rLevel;
    for (int i = 1; i < n; i++)
    {
        if (s.find(levelorder[i]) != s.end())
            lLevel.push_back(levelorder[i]);
        else
            rLevel.push_back(levelorder[i]);
    }
    Tree->pLeft = buildTree(inorder, lLevel, start, mid - 1, mid - start);
    Tree->pRight = buildTree(inorder, rLevel, mid + 1, end, end - mid);
    return Tree;
}
void postOrderTraversal(Node *Tree)
{
    if (Tree == NULL)
        return;
    postOrderTraversal(Tree->pLeft);
    postOrderTraversal(Tree->pRight);
    cout << Tree->data << " ";
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> inorder(n), levelorder(n);
    for (auto &x : inorder)
        cin >> x;
    for (auto &x : levelorder)
        cin >> x;
    Node *Tree = buildTree(inorder, levelorder, 0, n - 1, n);
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
