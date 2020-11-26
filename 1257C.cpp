#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// observation:
// if there are two items with same frequency in some subarray
// they are intersecting, one of them is the smaller subarray with more elements
// based on this observation, just pick the smallest available one and it is definitely valid

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        map<int, int> lastpos;
        int res = n+1;
        for(int i=0;i<n;i++) {
            if(lastpos.count(vals[i])) res = min(res, i-lastpos[vals[i]]+1);
            lastpos[vals[i]] = i;
        }
        cout << (res> n ? -1 : res) << "\n";
    }
}
