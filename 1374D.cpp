#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t,n,k,v;
    cin >> t;

    while(t--) {
        cin >> n >> k;
        map<ll, int> buckets;
        for(int i=0;i<n;i++) {
            cin >> v;
            v %= k;
            if(v==0) continue;
            buckets[k-v]++;
        }
        ll x = 0;
        for(auto p : buckets) {
            ll rem = p.first, v = p.second;
            if(v==0) continue;
            x = max(x, (v-1)*k+rem+1);
        }
        cout << x << endl;
    }
}
