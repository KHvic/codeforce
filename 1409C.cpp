#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main(){
    fastio
    ll t, n, x ,y;
    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        if(x>y) swap(x,y);
        int diff = y-x;
        int d = 1;
        int mxspace = n-1;
        for(;;d++) {
            if(diff%d == 0 && diff/d <= mxspace) {
                break;
            }
        }
        vector<int> res;
        res.push_back(x);
        res.push_back(y);
        // in between
        int mid = min(diff/d, mxspace) - 1;
        for(int i=1;i<=mid;i++) res.push_back(i*d+x);
        // left
        int cur = x-d;
        while(res.size()<n && cur>=1) {
            res.push_back(cur);
            cur -= d;
        }
        // right
        cur = y+d;
        while(res.size()<n) {
            res.push_back(cur);
            cur += d;
        }
        for(int i=0;i<res.size();i++) cout << res[i] << " \n"[i==res.size()-1];
    }
}
