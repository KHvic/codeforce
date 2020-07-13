#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a,b;
    cin >> a >> b;
    int target = 0;
    for(char c : a)
        target += c=='+'?1:-1;
    int cur = 0;
    int rand = 0;
    for(char c : b) {
        if(c=='?') rand++;
        else cur += c=='+'?1:-1;
    }
    int diff = abs(target-cur);
    vector<double> dp(2*rand+10,0);
    dp[rand] = 1.0;
    for(int x=0;x<rand;x++) {
        vector<double> dp_next(2*rand+10,0);
        for(int j=0;j<dp.size();j++) {
            if(j-1>=0) dp_next[j-1] += dp[j]/2.0;
            if(j+1<dp.size()) dp_next[j+1] += dp[j]/2.0;
        }
        dp = dp_next;
    }
    cout << fixed << setprecision(9);
    cout << dp[rand+diff];
}
