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
    stack<Node *> stk1, stk2;
    stk1.push(Tree);
    while (!stk1.empty() || !stk2.empty())
    {
        while (!stk1.empty())
        {
            Node *cur = stk1.top();
            stk1.pop();
            cout << cur->data << " ";
            if (cur->pRight != NULL)
                stk2.push(cur->pRight);
            if (cur->pLeft != NULL)
                stk2.push(cur->pLeft);
        }
        while (!stk2.empty())
        {
            Node *cur = stk2.top();
            stk2.pop();
            cout << cur->data << " ";
            if (cur->pLeft != NULL)
                stk1.push(cur->pLeft);
            if (cur->pRight != NULL)
                stk1.push(cur->pRight);
        }
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
