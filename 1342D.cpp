#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, k, v;
    cin >> n >> k;
    vector<int> cnt(k+1), lim(k+1);
    for(int i=0;i<n;i++) {
        cin >> v;
        cnt[v]++;
    }
    for(int i=1;i<=k;i++) cin >> lim[i];
    int mxsize = 0; // max pigeonhole size
    for(int i=k, sum=0;i>0;i--) {
        sum += cnt[i];
        mxsize = max(mxsize, (sum+lim[i]-1)/lim[i]);
    }
    vector<vector<int>> res(mxsize);
    // assign in round robin manner
    for(int i=k,idx=0;i>0;i--) {
        for(int j=0;j<cnt[i];j++,idx=(idx+1)%mxsize) res[idx].push_back(i);
    }
    cout << mxsize << "\n";
    for(auto& l : res) {
        cout << l.size();
        for(int x : l) cout << " " << x;
        cout << "\n";
    }
}
