#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fastio
    int n, k;
    cin >> n >> k;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    vector<pi> res;
    while(k--) {
        int mnpos = min_element(vals.begin(), vals.end()) - vals.begin();
        int mxpos = max_element(vals.begin(), vals.end()) - vals.begin();
        if(vals[mxpos] - vals[mnpos] <= 1) break;
        vals[mnpos]++;
        vals[mxpos]--;
        res.emplace_back(mxpos+1, mnpos+1);
    }
    int diff = *max_element(vals.begin(), vals.end()) - *min_element(vals.begin(), vals.end());
    cout << diff << " " << res.size() << "\n";
    for(auto p : res) cout << p.first << " " << p.second << "\n";
}
