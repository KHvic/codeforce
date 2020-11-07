#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    int res = 0;
    for(int v=1;v<=30;v++) {
        int cur = 0;
        for(int i=0;i<n;i++) {
            cur += vals[i] > v ? -1e7 : vals[i];
            cur = max(cur, 0);
            res = max(res, cur - v);
        }
    }
    cout << res;
}
