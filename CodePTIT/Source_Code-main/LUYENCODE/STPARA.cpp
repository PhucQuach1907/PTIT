#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        stack<int> stk;
        vector<int> car;
        car.push_back(0);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == car.back() + 1)
                car.push_back(a[i]);
            else
            {
                while (!stk.empty() && car.back() == stk.top() - 1)
                {
                    car.push_back(stk.top());
                    stk.pop();
                }
                stk.push(a[i]);
            }
        }
        while (!stk.empty() && car.back() == stk.top() - 1)
        {
            car.push_back(stk.top());
            stk.pop();
        }
        cout << (stk.empty() ? "yes\n" : "no\n");
    }
    return 0;
}
