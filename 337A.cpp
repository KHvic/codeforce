#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> vals(k);
    for(int i=0;i<k;i++) cin >> vals[i];
    int best = INT_MAX;
    sort(vals.begin(), vals.end());
    for(int i=0;i+n-1<k;i++) {
        best = min(best, vals[i+n-1] - vals[i]);
    }
    cout << best;
}
