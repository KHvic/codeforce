#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

vector<int> vals;

ll solve(int low, int hi, int offset) {
    if(low>hi) return 0;
    ll cost = hi-low+1;
    int mnidx = min_element(vals.begin()+low, vals.begin()+hi+1) - vals.begin();
    int mn = vals[mnidx];
    ll cost2 = solve(low,mnidx-1,mn) + solve(mnidx+1,hi,mn) + mn-offset;
    return min(cost, cost2);
}

int main(){
    fastio
    int n;
    cin >> n;
    vals = vector<int>(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    cout << solve(0, n-1, 0);
}
