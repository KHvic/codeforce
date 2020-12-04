#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int tc;
    string s, t, p;
    cin >> tc;
    while(tc--) {
        cin >> s >> t >> p;
        array<int, 26> cntextra, cntp;
        cntextra.fill(0); cntp.fill(0);
        int j = 0;
        for(int i=0;i<t.size();i++) {
            if(j<s.size() && s[j] == t[i]) j++;
            else cntextra[t[i]-'a']++;
        }
        if(j<s.size()) {
            cout << "NO\n"; continue;
        }
        for(char c : p) ++cntp[c-'a'];
        bool ok = true;
        for(int i=0;i<26&&ok;i++)
            ok &= cntextra[i] <= cntp[i];
        cout << (ok ? "YES\n" : "NO\n");
    }
}
