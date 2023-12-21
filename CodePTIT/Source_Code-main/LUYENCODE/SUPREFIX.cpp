#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e5 + 5;
int main()
{
    char a[MAX], b[MAX];
    scanf("%s%s", a, b);
    int index_a = 1, index_b = 1, len_a = strlen(a), len_b = strlen(b), start = 0;
    while (index_b <= len_b)
    {
        if (a[len_a - index_a] == b[len_b - index_b])
        {
            index_a++;
            index_b++;
            start++;
        }
        else
        {
            index_a = 1;
            index_b -= (start - 1);
            start = 0;
        }
    }
    printf("%s", a);
    for (int i = start; i < len_b; i++)
        printf("%c", b[i]);
    return 0;
}
