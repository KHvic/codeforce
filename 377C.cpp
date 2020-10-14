#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[21][1<<20];
bool flag[21][1<<20];

typedef pair<char, int> pp;

int main(){
    fastio
    int n, t, m;
    char o;
    cin >> n;
    vector<ll> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    sort(vals.rbegin(), vals.rend());
    cin >> m;
    vals.resize(n = min(m, n)); // limit by number of events
    flag[0][0] = true;
    vector<pp> events;
    for(int i=0;i<m;i++) {
        cin >> o >> t;
        events.emplace_back(o, t);
    }
    // reverse events in minimax dp
    reverse(events.begin(), events.end());
    for(int i=0;i<m;i++) {
        tie(o, t) = events[i];
        for(int j=0;j<(1<<n);j++) {
            if(!flag[i][j]) continue;
            if(t==1) {
                for(int k=0;k<n;k++) {
                    if(j&(1<<k)) continue;
                    int add = o == 'b' ? 0 : vals[k];
                    int nj = j | (1<<k);
                    int val = add+dp[i][j];
                    if(!flag[i+1][nj] || (val >= dp[i+1][nj])) {
                        dp[i+1][nj] = val, flag[i+1][nj] = true;
                    }
                }
            } else {
                for(int k=0;k<n;k++) {
                    if(j&(1<<k)) continue;
                    int add = o == 'b' ? 0 : -vals[k];
                    int nj = j | (1<<k);
                    int val = add+dp[i][j];
                    if(!flag[i+1][nj] || (val <= dp[i+1][nj])) {
                        dp[i+1][nj] = val, flag[i+1][nj] = true;
                    }
                }
            }
        }
    }
    cout << dp[m][(1<<n)-1];
}
