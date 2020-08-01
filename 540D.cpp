#include <bits/stdc++.h>
using namespace std;

int r, s, p;
vector<double> dp[101][101][101];

vector<double> solve(int r, int s, int p) {
    int total = r + s + p;
    if(total == r) return {1,0,0};
    else if(total == s) return {0,1,0};
    else if(total == p) return {0,0,1};
    else if(dp[r][s][p].size()) return dp[r][s][p];
    vector<double> res = {0,0,0};
    int killR = r*p;
    int killS = r*s;
    int killP = s*p;
    int totalKillWays = killR+killS+killP;
    if(r > 0) {
        double prob = 1.0*killR/totalKillWays;
        auto subres = solve(r-1,s,p);
        for(int i=0;i<3;i++)
            res[i] += prob*subres[i];
    }
    if(s > 0) {
        double prob = 1.0*killS/totalKillWays;
        auto subres = solve(r,s-1,p);
        for(int i=0;i<3;i++)
            res[i] += prob*subres[i];
    }
    if(p > 0) {
        double prob = 1.0*killP/totalKillWays;
        auto subres = solve(r,s,p-1);
        for(int i=0;i<3;i++)
            res[i] += prob*subres[i];
    }
    return dp[r][s][p] = res;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> r >> s >> p;
    auto res = solve(r, s, p);
    cout << fixed << setprecision(12);
    cout << res[0] << " " << res[1] << " " << res[2];
}
