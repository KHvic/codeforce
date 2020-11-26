#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int tc;
    string s, t;
    cin >> tc;
    while(tc--) {
        cin >> s >> t;
        int n = s.size();
        vector<vector<int>> nxt(n+1, vector<int>(26, 1e8));
        for(int i=n-1;i>=0;i--) {
            nxt[i] = nxt[i+1];
            nxt[i][s[i]-'a'] = i;
        }

        int res = 1, cur = 0;
        bool ok = true;
        for(char c : t) {
            int idx = c-'a';
            if(cur>=n || nxt[cur][idx]>=n) {
                res++;
                cur = 0;
            }
            if(nxt[cur][idx]>=n) {
                ok = false;
                break;
            }
            cur = nxt[cur][idx]+1;
        }
        cout << (ok ? res : -1) << "\n";
    }
}
