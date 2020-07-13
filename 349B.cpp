#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v;
    cin >> v;
    vector<int> cost(9);
    int mn = INT_MAX, bestIdx=0;
    // find cheapest index
    for(int i=0;i<9;i++) {
        cin >> cost[i];
        if(cost[i] <= mn) {
            bestIdx = i;
            mn = cost[i];
        }
    }
    int mxcnt = v/mn;
    if(mxcnt == 0) {
        cout << -1;
        return 0;
    }
    v -= mxcnt*mn;
    string res(mxcnt, bestIdx+'1');
    for(int i=0;i<res.size();i++) {
        // try to swap with largest number
        for(int j=8;j>=0;j--) {
            int swapCost = cost[j] - mn;
            if(v>=swapCost) {
                res[i] = (j+'1');
                v -= swapCost;
                break;
            }
        }
    }
    cout << res;
}
