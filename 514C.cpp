#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const ll mod = 1000000007;
const ll p = 257;

int n, m;
set<ll> hshset;
ll powp[N];

ll compute_hash(string& s) {
    int n = s.size();
    ll res = 0;
    for(int i=0;i<n;i++)
        res = (res*p + s[i]) % mod;
    return res;
}

void init() {
    powp[0] = 1;
    for(int i=1;i<N;i++) powp[i] = (powp[i-1] * p) % mod;
}

ll hashOfPosition(int idx, char c) {
    return (powp[idx]*c) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    init();
    string s;
    for(int i=0;i<n;i++) {
        cin >> s;
        hshset.insert(compute_hash(s));
    }
    for(int i=0;i<m;i++) {
        cin >> s;
        bool found = false;
        ll hsh = compute_hash(s);
        int len = s.size();
        for(int j=0;j<len && !found;j++) {
            for(char c='a';c<='c' && !found;c++) {
                if(s[j] == c) continue;
                ll nxthsh = hsh + hashOfPosition(len-1-j, c-s[j]);
                nxthsh = ((nxthsh % mod) + mod) % mod;
                if(hshset.count(nxthsh)) found = true;
            }
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
}
