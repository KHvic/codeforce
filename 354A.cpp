#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main()
{
    fastio
    int n,l,r,c1,c2;
    cin >> n >> l >> r >> c1 >> c2;
    ll right_sum = 0, left_sum = 0;
    vector<ll> vals(n);
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        right_sum += vals[i];
    }
    ll res = right_sum*r + (n-1)*c2;
    for(int i=0,j=n-1,k=1;i<n;i++,j--,k++) {
        right_sum -= vals[i];
        left_sum += vals[i];
        ll cost = left_sum*l + right_sum*r;
        if(j>k) {
            int repeat = j-k-1;
            cost += repeat*c2;
        } else if(k>j) {
            int repeat = k-j-1;
            cost += repeat*c1;
        }
        res = min(res, cost);
    }
    cout << res;
}
