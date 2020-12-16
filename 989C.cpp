#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int cnt[4];
    for(int i=0;i<4;i++) cin >> cnt[i];
    cout << "50 50\n";
    vector<string> res;
    cnt[0]--; cnt[1]--;
    for(int i=0;i<50;i++) {
        if(i<25) res.push_back(string(50, 'A'));
        else res.push_back(string(50, 'B'));
    }
    for(int i=0;i<25;i+=2) {
        for(int j=0;j<50;j+=2) {
            for(int k=0;k<4;k++) {
                if(k==0) continue;
                if(cnt[k]) {
                    cnt[k]--;
                    res[i][j] = (char)('A'+k);
                    break;
                }
            }
        }
    }
    for(int i=26;i<50;i+=2) {
        for(int j=0;j<50;j+=2) {
            for(int k=0;k<4;k++) {
                if(k==1) continue;
                if(cnt[k]) {
                    cnt[k]--;
                    res[i][j] = (char)('A'+k);
                    break;
                }
            }
        }
    }
    for(string& s : res) cout << s << "\n";
}
