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
    queue<Node *> q;
    q.push(Tree);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->pLeft != NULL)
            q.push(cur->pLeft);
        if (cur->pRight != NULL)
            q.push(cur->pRight);
    }
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
