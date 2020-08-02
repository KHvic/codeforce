#include <bits/stdc++.h>
using namespace std;
#define ll long long

string avail;
int k;
vector<vector<vector<int>>> dp;
int offset = 10;
vector<int> path;

int solve(int balance, int left, int last) {
    if(left == 0) return true;
    else if(balance>9 || balance<-9) return false;
    else if(dp[balance+offset][left][last] == false)
        return false;
    bool left_turn = (k-left) % 2 == 0;
    for(int i=1;i<=10;i++) {
        if(avail[i-1] == '0' || i == last) continue;
        int nbalance = balance;
        if(left_turn) {
            nbalance -= i;
            if(nbalance>=0) continue;
        } else {
            nbalance += i;
            if(nbalance<=0) continue;
        }
        path.push_back(i);
        if(solve(nbalance, left-1, i)) return true;
        path.pop_back();
    }
    return dp[balance+offset][left][last] = false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> avail >> k;
    dp.assign(25,vector<vector<int>>(k+1,vector<int>(11,-1)));
    int res = solve(0, k, 0);
    if(!res) {
        cout << "NO\n"; return 0;
    }
    cout << "YES\n";
    for(int i=0;i<k;i++) {
        if(i) cout << " ";
        cout << path[i];
    }
}
