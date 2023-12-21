#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int res;
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
int Max_sum_of_two_leaf(Node *Tree)
{
    if (!Tree)
        return 0;
    if (!Tree->pLeft && !Tree->pRight)
        return Tree->data;
    int l = Max_sum_of_two_leaf(Tree->pLeft);
    int r = Max_sum_of_two_leaf(Tree->pRight);
    if (Tree->pLeft && Tree->pRight)
    {
        res = max(res, l + r + Tree->data);
        return (max(l, r) + Tree->data);
    }
    return (!Tree->pLeft ? r + Tree->data : l + Tree->data);
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
    res = INT_MIN;
    int calc = Max_sum_of_two_leaf(Tree);
    cout << res << "\n";
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
