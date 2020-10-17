#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    fastio
    string s, rs, t, rt;
    int m;
    cin >> s >> m;
    rs = s;
    reverse(rs.begin(), rs.end());
    int res = 0;
    while(m--) {
        cin >> t;
        if(t.size()==1) continue;
        rt = t;
        reverse(rt.begin(), rt.end());
        string p1 = t + "$" + s, p2 = rt + "$" + rs;
        auto z1 = z_function(p1), z2 = z_function(p2);
        vector<int> pref(s.size(), 0), suff(s.size());
        for(int i=0;i<s.size();i++) {
            int idx = i+t.size()+1;
            pref[i+z1[idx]-1] = max(pref[i+z1[idx]-1], z1[idx]);
            suff[i+z2[idx]-1] = max(suff[i+z2[idx]-1], z2[idx]);
        }
        for(int i=1;i<s.size();i++) {
            pref[i] = max(pref[i], pref[i-1]);
            suff[i] = max(suff[i], suff[i-1]);
        }
        reverse(suff.begin(), suff.end());
        bool ok = false;
        // check if two non overlapping segment >= t size
        // also can use kmp
        for(int i=0;i<s.size()-1&&!ok;i++) {
            ok |= pref[i] + suff[i+1] >= t.size();
        }
        if(ok || s==t) res++;
    }
    cout << res;
}
