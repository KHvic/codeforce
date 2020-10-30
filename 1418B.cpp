#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, v;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vals(n);
        vector<bool> locked(n);
        vector<int> rearrange;
        for(int i=0;i<n;i++) cin >> vals[i];
        for(int i=0;i<n;i++) {
            cin >> v, locked[i] = v;
            if(!locked[i]) rearrange.push_back(vals[i]);
        }
        sort(rearrange.rbegin(), rearrange.rend());
        for(int i=0,j=0;i<n;i++) {
            if(!locked[i]) vals[i] = rearrange[j++];
            cout << vals[i] << " \n"[i==n-1];
        }
    }
}
