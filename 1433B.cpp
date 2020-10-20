#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main(){
    fastio
    int t,n,v;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> pos, vals(n), vals2;
        for(int i=0;i<n;i++) cin >> vals[i];
        int idx = 0;
        for(int i=0;i<n;i++) {
            if(vals[i]==1 && (i==n-1 || vals[i+1] == 0)) {
                vals2.push_back(1);
            } else if(vals[i] == 0) vals2.push_back(0);
        }
        for(int i=0;i<vals2.size();i++)
            if(vals2[i] == 1) pos.push_back(i);
 
        int res = 0;
        for(int i=1;i<pos.size();i++) res += (pos[i] - pos[i-1] - 1);
        cout << res << "\n";
    }
}
