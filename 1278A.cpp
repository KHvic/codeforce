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
        map<char, int> cnt, cnt2;
        bool ok = false;
        for(char c : s) cnt[c]++;
        int invalid = 0;
        int i = 0, j = 0;
        while(i<t.size()) {
            if(++cnt2[t[i]] > cnt[t[i]]) invalid++;
            i++;
            while(invalid) {
                if(cnt2[t[j]]-- > cnt[t[j]]) invalid--;
                j++;
            }
            if(i-j == s.size()) ok = true;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
