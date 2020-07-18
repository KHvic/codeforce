#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MX = sqrt(1e12) + 10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> vals(n);
    ll mx = 0, sum = 0;
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        mx = max(mx, vals[i]);
        sum += vals[i];
    }
    ll lo = mx, hi = sum;
    while(lo<hi) {
        ll mid = (lo+hi) >> 1; // number of games played
        // compute total number supervise all player
        ll mxSupervise = mid*n - sum;
        // if this number is larger than number of game played, we can achieve it
        if(mxSupervise>=mid) hi = mid;
        else lo = mid+1;
    }
    cout << lo;
}
