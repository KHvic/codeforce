#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int n;
vector<int> a;

int solve(int l, int r, int h) {
    if(l>r) return 0;
    auto mn = min_element(a.begin()+l, a.begin()+r+1);
    int mn_val = *mn;
    int mn_idx = mn-a.begin();
    int left = solve(l, mn_idx-1, mn_val);
    int right = solve(mn_idx+1, r, mn_val);
    int horizon_cost = mn_val - h;

    return min(r-l+1, left+right+horizon_cost);
}

int main(){
    fastio
    int n;
    cin >> n;
    a.assign(n, 0);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << solve(0, n-1, 0);
}
