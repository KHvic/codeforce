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
        int n = s.size();
        vector<int> cnt;
        for(int i=0, cur=0;i<n;i++) {
            cur += s[i]=='1';
            if(i==n-1||s[i+1] == '0') {
                if(cur) cnt.push_back(cur);
                cur = 0;
            }
        }
        sort(cnt.rbegin(), cnt.rend());
        int res = 0;
        for(int i=0;i<cnt.size();i+=2) res += cnt[i];
        cout << res << "\n";
    }
}
