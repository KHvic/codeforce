#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t;
    cin >> t;
    string s;
    while(t--) {
        cin >> s;
        int n = s.size();
        vector<set<int>> graph(26);
        bool vis[26];
        memset(vis, 0, sizeof vis);
        for(int i=0;i<n;i++) {
            if(i) graph[s[i]-'a'].insert(s[i-1]-'a');
            if(i<n-1) graph[s[i]-'a'].insert(s[i+1]-'a');
        }

        string res;
        function<void(int)> dfs = [&](int x) -> void {
            vis[x] = true;
            res += string(1, x+'a');
            for(int v : graph[x])
                if(!vis[v] && graph[v].size() <= 2) dfs(v);
        };

        for(int i=0;i<26;i++)
            if(!vis[i] && graph[i].size() <= 1)
                dfs(i);
        if(res.size() != 26) cout << "NO\n";
        else cout << "YES\n" << res << "\n";
    }
}
