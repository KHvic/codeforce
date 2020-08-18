#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc,n,v;
    cin >> tc;
    while(tc--) {
        cin >> n;
        vector<ll> v1(n), v2(n);
        ll mnA = 1e11, mnB = 1e11;
        for(int i=0;i<n;i++) {cin >> v1[i]; mnA = min(mnA, v1[i]);}
        for(int i=0;i<n;i++) {cin >> v2[i]; mnB = min(mnB, v2[i]);}
        ll res = 0;
        for(int i=0;i<n;i++) {
            ll needA = v1[i] - mnA, needB = v2[i] - mnB;
            res += max(needA, needB);
        }
        cout << res << "\n";
    }
}
