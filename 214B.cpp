#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // a number dividable by 5 and 2 must end with 0
    // a number dividable by 3 must have sum of all digit dividable by 3
    int n, v;
    int sum = 0;
    int cnt[10];
    memset(cnt, 0, sizeof cnt);
    cin >> n;
    while(n--) {
        cin >> v;
        cnt[v]++;
        sum += v;
    }
    if(cnt[0]==0) {
        cout << "-1";
        return 0;
    }
    int mod = sum%3;
    if(mod!=0) {
        bool deleted = 0;
        for(int i=mod;i<9;i+=3) {
            if(cnt[i]>0) {
                deleted = 1;
                cnt[i]--;
                break;
            }
        }
        // for mod2, try delete two ones or mod1, try delete two twos
        if(!deleted) {
            int left=2;
            for(int i=mod==1?2:1;i<9 && left;i+=3) {
                int take = min(left, cnt[i]);
                left -= take;
                cnt[i] -= take;
            }
        }
    }
    string res;
    for(int i=9;i>=0;i--) {
        if(i==0 && res.empty()) cnt[0] = 1;
        res += string(cnt[i], '0'+i);
    }
    cout << res;
}
