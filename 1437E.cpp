#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, k, b;
    cin >> n >> k;
    vector<int> vals(n+2), fixed;
    vals[0] = -1e8; vals[n+1] = 2e9;
    for(int i=1;i<=n;i++) cin >> vals[i], vals[i] -= i; // zeroing technique to account for position constraint
    fixed.push_back(0);
    while(k--) {
        cin >> b;
        fixed.push_back(b);
    }
    fixed.push_back(n+1);
    int res = 0;
    for(int i=0;i<fixed.size()-1;i++) {
        int l = fixed[i], r = fixed[i+1];
        if(vals[l] > vals[r]) {
            cout << -1; return 0;
        }
        vector<int> lis;
        for(int j=l+1;j<r;j++)
        if(vals[l] <= vals[j] && vals[j] <= vals[r])
        {
            auto it = upper_bound(lis.begin(), lis.end(), vals[j]);
            if(it==lis.end()) lis.push_back(vals[j]);
            else *it = vals[j];
        }
        res += (r-(l+1)) - lis.size();
    }
    cout << res;
}
