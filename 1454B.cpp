#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> cnt(n+1);
        map<int, int> pos;
        for(int i=0,v=0;i<n;i++) {
            cin >> v;
            cnt[v]++;
            pos[v] = (i+1);
        }
        int res = -1;
        for(int i=1;i<=n;i++)
        if(cnt[i] == 1) {
            res = i;
            break;
        }
        cout << (res==-1 ? -1 : pos[res]) << "\n";
    }
}
