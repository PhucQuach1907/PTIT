#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int leaf_level;
bool ok;
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
void addNode(Node *&Tree, int parent, int child, char c)
{
    if (Tree == NULL)
        return;
    if (Tree->data == parent)
    {
        if (c == 'L')
            Tree->pLeft = makeNode(child);
        else
            Tree->pRight = makeNode(child);
        return;
    }
    addNode(Tree->pLeft, parent, child, c);
    addNode(Tree->pRight, parent, child, c);
}
void isPerfectTree(Node *Tree, int level)
{
    if (Tree == NULL || !ok)
        return;
    if (Tree->pLeft == NULL && Tree->pRight == NULL)
    {
        if (leaf_level == -1)
            leaf_level = level;
        else if (leaf_level != level)
        {
            ok = 0;
            return;
        }
    }
    if ((Tree->pLeft == NULL && Tree->pRight != NULL) || (Tree->pRight == NULL && Tree->pLeft != NULL))
    {
        ok = 0;
        return;
    }
    isPerfectTree(Tree->pLeft, level + 1);
    isPerfectTree(Tree->pRight, level + 1);
}
void Solve()
{
    int n;
    cin >> n;
    Node *Tree = NULL;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (i == 0)
            Tree = makeNode(u);
        addNode(Tree, u, v, c);
    }
    leaf_level = -1, ok = 1;
    isPerfectTree(Tree, 1);
    cout << (ok ? "Yes\n" : "No\n");
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
