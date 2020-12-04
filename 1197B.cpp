#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n;
    cin >> n;
    vector<int> vals(n);
    int mxidx = 0;
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        if(vals[i] > vals[mxidx]) mxidx = i;
    }
    vector<int> cpy = vals;
    sort(cpy.rbegin(), cpy.rend());
    int l = mxidx, r = mxidx;
    bool ok = true;
    for(int i=1;i<n&&ok;i++) {
        if(l-1>=0 && vals[l-1] == cpy[i]) l--;
        else if(r+1<n && vals[r+1] == cpy[i]) r++;
        else ok = false;
    }
    cout << (ok ? "YES" : "NO");
}
