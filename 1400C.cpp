#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t,x;
    string s;
    cin >> t;
    while(t--) {
        cin >> s >> x;
        int n = s.size();
        string res(n, '1');
        for(int i=0;i<s.size();i++) {
            if(s[i] == '0') {
                if(i-x>=0) res[i-x] = '0';
                if(i+x<n) res[i+x] = '0';
            }
        }
        bool ok = true;
        for(int i=0;i<n&&ok;i++)
            if(s[i]=='1' && ((i-x<0 || res[i-x]!='1') && (i+x>=n || res[i+x]!='1'))) ok = false;
        if(ok) cout << res << "\n";
        else cout << "-1\n";
    }
}
