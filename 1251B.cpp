#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int q, n;
    string s;
    cin >> q;
    while(q--) {
        cin >> n;
        int zero = 0, one = 0;
        int odd = 0, even = 0;
        for(int i=0;i<n;i++) {
            cin >> s;
            for(char c : s)
                (c == '0' ? zero : one)++;
            (s.size()&1 ? odd : even)++;
        }
        // observe that answer is always n or n-1
        int res = n;
        int cntodd = (zero&1) + (one&1);
        if(cntodd > odd) res--; // too little odd sized string
        cout << res << "\n";
    }
}
