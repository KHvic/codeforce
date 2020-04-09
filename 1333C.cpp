#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,v;
    scanf("%lld",&n);
    map<ll,ll> posMap; // cumulative sum latest position
    posMap[0] = -1;
    ll sum = 0;
    ll res = 0;
    ll maxInvalid = -1; // track rightmost invalid position
    for(int i=0;i<n;i++) {
        scanf("%lld",&v);
        sum += v;
        if(posMap.count(sum)) maxInvalid = max(maxInvalid, posMap[sum]+1);
        posMap[sum] = i;
        res += (i-maxInvalid);
    }
    printf("%lld\n",res);
}
