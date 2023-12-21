#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<long long> a1(n1), a2(n2), a3(n3);
        for (auto &c : a1)
            cin >> c;
        for (auto &c : a2)
            cin >> c;
        for (auto &c : a3)
            cin >> c;
        int i = 0, j = 0, k = 0;
        vector<long long> store;
        while (i < n1 && j < n2 && k < n3)
        {
            if (a1[i] == a2[j] && a2[j] == a3[k])
            {
                store.push_back(a1[i]);
                i++, j++, k++;
            }
            else if (a1[i] < a2[j])
                i++;
            else if (a2[j] < a3[k])
                j++;
            else
                k++;
        }
        if (store.size() == 0)
            cout << -1;
        else
        {
            for (auto c : store)
                cout << c << " ";
        }
        cout << "\n";
    }
    return 0;
}