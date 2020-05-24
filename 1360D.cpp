#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t,n,k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        int res = n;
        if(k>=n) res = 1;
        else {
            for(ll i=1;i*i<=n && i<=k;i++) {
                if(n%i == 0 && n/i <= k) {
                    res = i;
                    break;
                } else if(n%i==0) res = n/i;
            }
        }
        printf("%d\n", res);
    }
}
