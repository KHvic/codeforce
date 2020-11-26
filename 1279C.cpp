#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n, m, v;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<int> pos(n+1);
        for(int i=0;i<n;i++) {
            cin >> v;
            pos[v] = i+1;
        }
        int mxdepth = 0;
        ll res = 0;
        for(int i=0;i<m;i++) {
            cin >> v;
            int p = pos[v];
            if(p < mxdepth) res++;
            else {
                ll cost = pos[v] - i;
                res += cost + (cost-1); // put back
                mxdepth = p;
            }
        }
        cout << res << "\n";
    }
}
