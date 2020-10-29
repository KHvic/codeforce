#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        int res = 1;
        int mn = -1;
        int left = 1, next=0;
        for(int i=1;i<n;i++) {
            if(vals[i] < mn) {
                left--; // use up current parent node
                if(left==0) {
                    // new level
                    res++;
                    left = next;
                    next = 1; // itself
                } else {
                    // same level, other par
                    next++;
                }
            } else {
                next++; // next level how many nodes
            }
            mn = vals[i];
        }
        cout << res << "\n";
    }
}
