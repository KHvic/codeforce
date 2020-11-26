#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        int n = s.size(), cnt1 = count(s.begin(), s.end(), '1');
        int cnt2 = n - cnt1;
        string res;
        if(cnt1==0 || cnt2==0) res = s;
        else {
            int mx = max(cnt2, cnt1);
            int c = s[0]-'0';
            for(;res.size()+2<=n*2;) {
                res += to_string(c);
                res += to_string(c^1);
            }
        }
        cout << res << "\n";
    }
}
