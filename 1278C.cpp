#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vals(2*n);
        for(int i=0;i<2*n;i++) cin >> vals[i];
        int offset = 0;
        for(int x : vals) offset += x == 1 ? 1 : -1;
        if(offset==0) {
            cout << "0\n";
            continue;
        }

        map<int, int> prefixidx;
        prefixidx[0] = 0;
        for(int i=1,cur=0;i<=n;i++) {
            cur += vals[n-i] == 1 ? 1 : -1;
            if(!prefixidx.count(cur)) prefixidx[cur] = i;
        }
        int res = 2*n;
        if(prefixidx.count(offset)) res = prefixidx[offset];
        for(int i=1,cur=0;i<=n;i++) {
            cur += vals[n-1+i] == 1 ? 1 : -1;
            int complement = offset-cur;
            if(prefixidx.count(complement)) res = min(res, i+prefixidx[complement]);
        }
        cout << res << "\n";
    }
}
