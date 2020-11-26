#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    ll x;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        vector<ll> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        sort(vals.rbegin(), vals.rend());
        ll sum = 0;
        int i=0;
        for(;i<n;){
            sum += vals[i];
            double avg = sum/(i+1);
            if(avg>=x) i++;
            else break;
        }
        cout << i << "\n";
    }
}
