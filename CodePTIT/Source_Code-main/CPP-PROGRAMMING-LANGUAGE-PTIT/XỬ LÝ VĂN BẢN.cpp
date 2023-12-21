#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{
    vector<string> a;
    char s[250], text[20005] = {};
    while (fgets(s, sizeof(s), stdin))
    {
        char *p = strtok(s, " \t\n");
        while (p != NULL)
        {
            strcat(text, p);
            strcat(text, " ");
            p = strtok(NULL, " \t\n");
        }
    }
    text[strlen(text) - 1] = '\0';
    for (int i = 0; i < strlen(text); i++)
        text[i] = (text[i] >= 'A' && text[i] <= 'Z' ? text[i] + 32 : text[i]);
    char *p = strtok(text, ".?!");
    while (p != NULL)
    {
        a.push_back(p);
        p = strtok(NULL, ".?!");
    }
    for (int i = 0; i < a.size(); i++)
    {
        while (a[i][0] == ' ')
            a[i].erase(0, 1);
        a[i][0] -= 32;
        cout << a[i] << "\n";
    }
    return 0;
}