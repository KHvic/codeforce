#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w,b;

vector<vector<double>> dp;

double solve(int w, int b) {
    if(w<=0 || b<0) return 0;
    else if(w==1 && b==0) return 1;
    else if(dp[w][b] != -1) return dp[w][b];
    double total = w+b;
    double whiteP = 1.0*w/total;
    double res = whiteP;

    // princess choose black
    if(total-2>0) {
        double probBlack = 1.0 - whiteP;
        double probDragonBlack = 1.0*(b-1)/(total-1);
        double whiteMiceJump = 1.0*w/(total-2);
        double blackMiceJump = 1.0 - whiteMiceJump;
        res += probBlack*probDragonBlack*(blackMiceJump*solve(w,b-3) + whiteMiceJump*solve(w-1,b-2));
    }
    return dp[w][b] = res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> w >> b;
    dp.assign(w+1, vector<double>(b+1, -1));
    cout << fixed << setprecision(9);
    cout << solve(w, b) << "\n";
}
