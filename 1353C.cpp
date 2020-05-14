#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    int t;
    ll n;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld",&n);
        n/=2;
        ll res = 8*n*(n+1)*(2*n+1)/6;
        printf("%lld\n", res);
    }
}
