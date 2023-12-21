#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
vector<int> a;
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
void BTtoArray(Node *Tree)
{
    if (!Tree)
        return;
    BTtoArray(Tree->pLeft);
    a.push_back(Tree->data);
    BTtoArray(Tree->pRight);
}
void Solve()
{
    a.clear();
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
    BTtoArray(Tree);
    sort(a.begin(), a.end());
    for (auto x : a)
        cout << x << " ";
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
