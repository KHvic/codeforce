#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

 
ll t, n, k;
 
int main(){
    fastio
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<ll> xs(n), ys(n);
        for(int i=0;i<n;i++) cin >> xs[i];
        for(int i=0;i<n;i++) cin >> ys[i];
 
        sort(xs.begin(), xs.end());
        vector<ll> left(n);
        queue<ll> pts;
        for(int i=0;i<n;i++) {
            int curx = xs[i];
            while(!pts.empty() && curx - pts.front() > k) pts.pop();
            pts.push(curx);
            left[i] = pts.size();
            if(i) left[i] = max(left[i], left[i-1]);
        }
        queue<ll> pts2;
        ll rightmx = 0;
        ll res = 0;
        for(int i=n-1;i>=0;i--) {
            int curx = xs[i];
            while(!pts2.empty() && pts2.front() - curx > k) pts2.pop();
            pts2.push(curx);
            rightmx = max(rightmx, (ll)pts2.size());
            ll best = rightmx + (i==0 ? 0 : left[i-1]);
            res = max(best, res);
        }
        cout << res << "\n";
    }
}
