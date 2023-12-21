#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node
{
    string data;
    Node *pLeft;
    Node *pRight;
};
Node *makeNode(string d)
{
    Node *tmp = new Node;
    tmp->data = d;
    tmp->pLeft = tmp->pRight = NULL;
    return tmp;
}
void Convert_To_Binary_Tree(int n, vector<string> a, Node *&Tree)
{
    int i = 0;
    Tree = makeNode(a[0]);
    i++;
    queue<Node *> q;
    q.push(Tree);
    while (i < n)
    {
        Node *parent = q.front();
        q.pop();
        Node *childLeft = NULL, *childRight = NULL;
        childLeft = makeNode(a[i]);
        i++;
        q.push(childLeft);
        if (i < n)
        {
            childRight = makeNode(a[i]);
            q.push(childRight);
            i++;
        }
        parent->pLeft = childLeft;
        parent->pRight = childRight;
    }
}
bool isOperator(string s)
{
    return (s == "+" || s == "-" || s == "*" || s == "/");
}
string Calc(string a, string b, string o)
{
    int num1 = stoi(a), num2 = stoi(b);
    int ans;
    if (o == "+")
        ans = num1 + num2;
    else if (o == "-")
        ans = num1 - num2;
    else if (o == "*")
        ans = num1 * num2;
    else
        ans = num1 / num2;
    return to_string(ans);
}
void DFT(Node *&Tree)
{
    if (!isOperator(Tree->data))
        return;
    DFT(Tree->pLeft);
    DFT(Tree->pRight);
    Tree->data = Calc(Tree->pLeft->data, Tree->pRight->data, Tree->data);
}
void Solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    Node *Tree;
    Convert_To_Binary_Tree(n, a, Tree);
    DFT(Tree);
    cout << Tree->data << "\n";
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
