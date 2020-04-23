#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, v;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &v);
        ll i = 2;
        while ((v % ((ll)pow(2, i) - 1)) != 0)
            i++;
        printf("%d\n", (v / ((ll)pow(2, i) - 1)));
    }
}