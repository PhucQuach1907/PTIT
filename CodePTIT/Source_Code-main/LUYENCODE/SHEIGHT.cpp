#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node
{
    char data;
    Node *pLeft;
    Node *pRight;
};
Node *makeNode(char d)
{
    Node *tmp = new Node;
    tmp->data = d;
    tmp->pLeft = tmp->pRight = NULL;
    return tmp;
}
Node *makeNode2(char d, Node *L, Node *R)
{
    Node *tmp = new Node;
    tmp->data = d;
    tmp->pLeft = L;
    tmp->pRight = R;
}
Node *buildTree(string s)
{
    stack<Node *> stk;
    for (char x : s)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        {
            Node *R = stk.top();
            stk.pop();
            Node *L = stk.top();
            stk.pop();
            stk.push(makeNode2(x, L, R));
        }
        else
            stk.push(makeNode(x));
    }
    return stk.top();
}
int height(Node *Tree)
{
    if (!Tree)
        return -1;
    return 1 + max(height(Tree->pLeft), height(Tree->pRight));
}
void Solve()
{
    string s;
    cin >> s;
    Node *Tree = buildTree(s);
    cout << height(Tree) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
