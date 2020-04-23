#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t, n, v;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int half = n / 2;
        if ((half) % 2 == 1)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for (int i = 1; i <= half; i++)
                printf("%d ", i * 2);
            for (int i = 1; i < half; i++)
                printf("%d ", i * 2 - 1);
            printf("%d\n", (half * 2 - 1 + half));
        }
    }
}
