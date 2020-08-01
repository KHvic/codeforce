#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, l, r;
    cin >> n >> m;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];

    vector<int> nxtPeak(n, n-1), nxtBtm(n, n-1);
    for(int i=n-2;i>=0;i--) {
        if(vals[i] >= vals[i+1]) {
            nxtBtm[i] = nxtBtm[i+1];
        } else nxtBtm[i] = i;
        if(vals[i] <= vals[i+1]) {
            nxtPeak[i] = nxtPeak[i+1];
        } else nxtPeak[i] = i;
    }
    while(m--) {
        cin >> l >> r;
        l--; r--;
        int furthest = nxtBtm[nxtPeak[l]];
        cout << (furthest >= r ? "Yes" : "No") << "\n";
    }
}
