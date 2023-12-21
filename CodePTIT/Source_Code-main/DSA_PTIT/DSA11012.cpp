#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
void Check(Node *Tree1, Node *Tree2)
{
    if (!ok)
        return;
    if (Tree1 == NULL || Tree2 == NULL)
    {
        if (Tree1 != Tree2)
            ok = 0;
        return;
    }
    if (Tree1->data != Tree2->data)
    {
        ok = 0;
        return;
    }
    Check(Tree1->pLeft, Tree2->pLeft);
    Check(Tree1->pRight, Tree2->pRight);
}
void Solve()
{
    int n;
    cin >> n;
    Node *Tree1 = NULL;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (i == 0)
            Tree1 = makeNode(u);
        addNode(Tree1, u, v, c);
    }
    int m;
    cin >> m;
    Node *Tree2 = NULL;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (i == 0)
            Tree2 = makeNode(u);
        addNode(Tree2, u, v, c);
    }
    ok = 1;
    Check(Tree1, Tree2);
    cout << ok << "\n";
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
