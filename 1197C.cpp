#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n, k;
    cin >> n >> k;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    vector<ll> diff;
    for(int i=1;i<n;i++) diff.push_back(vals[i] - vals[i-1]);
    ll sum = accumulate(diff.begin(), diff.end(), 0LL);
    
    // top k-1 diff splitting can be reduced
    sort(diff.rbegin(), diff.rend());
    for(int i=0;i<k-1;i++) sum -= diff[i];
    cout << sum;
}
