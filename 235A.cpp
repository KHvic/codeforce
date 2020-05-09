#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    scanf("%lld",&n);
    if(n<=2) printf("%lld", n);
    else if(n%2) printf("%lld",(ll)n*(n-1)*(n-2));
    else if(n%3) printf("%lld",(ll)n*(n-1)*(n-3)); // even odd odd
    else printf("%lld",(ll)(n-1)*(n-2)*(n-3)); // case when (n-3) and (n) is both divisible by 3
}
