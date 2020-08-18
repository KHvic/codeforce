#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc,n,v;
    string s;
    cin >> tc;
    while(tc--) {
        cin >> n;
        cin >> s;
        vector<int> res(n), one, zero;
        int mx = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '0') {
                if(zero.empty()) zero.push_back(++mx);
                res[i] = zero.back();
                one.push_back(zero.back());
                zero.pop_back();
            } else {
                if(one.empty()) one.push_back(++mx);
                res[i] = one.back();
                zero.push_back(one.back());
                one.pop_back();
            }
        }
        cout << mx << "\n";
        for(int i=0;i<n;i++) {
            if(i) cout << " ";
            cout << res[i];
        }
        cout << "\n";
    }
}
