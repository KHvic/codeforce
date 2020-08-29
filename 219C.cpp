#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int res = 0;
    // two case, when k=2, pick either ABA.. or BAB...
    if(k==2) {
        int cnt=0;
        for(int i=0;i<n;i++) {
            char tar = 'A' +i%2;
            if(s[i] != tar) cnt++;
        }
        int cnt2 = n-cnt;
        s = "";
        if(cnt<cnt2) {
            res = cnt;
            for(int i=0;i<n;i++) s += ('A'+i%2);
        } else {
            res = cnt2;
            for(int i=0;i<n;i++) s += ('B'-i%2);
        }
    } else {
        // case 2, k>2, greedy pick non adjacent to swap to
        for(int i=1;i<n;i++) {
            if(s[i] == s[i-1]) {
                res++;
                char c = 'A';
                for(int j=0;j<k;j++,c++) {
                    if(c!=s[i-1] && (i==n-1 || s[i+1]!=c)) break;
                }
                s[i] = c;
            }
        }
    }
    cout << res << "\n" << s;
}
