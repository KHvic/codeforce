#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    cin >> t;
    string s;
    while(t--) {
        cin >> s;
        int n = s.size();
        ll res = 0;
        for(int i=0,cnt0=0;i<n;i++) {
            if(s[i]=='0') cnt0++;
            else {
                // constant time, at around 17 bits >= 1e5
                for(int j=i,f=0,len=cnt0+1;j<n;j++,len++) {
                    f <<= 1;
                    f += s[j]=='1';
                    if(f<=len) res++;
                    else break;
                }
                cnt0 = 0;
            }
        }
        cout << res << "\n";
    }
}
