#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int q, n, r;
    cin >> q;
    while(q--) {
        cin >> n >> r;
        vector<int> pos(n);
        for(int i=0;i<n;i++) cin >> pos[i];
        sort(pos.rbegin(), pos.rend());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        int res = 0;
        for(int i=0;i<pos.size();i++) {
            int push = i*r;
            if(push >= pos[i]) break;
            else res++;
        }
        cout << res << "\n";
    }
}
