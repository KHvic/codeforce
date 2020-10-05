#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main()
{
    fastio
    ll n, m;
    cin >> m >> n;
    vector<ll> pages(n);
    for(int i=0;i<n;i++) {
        cin >> pages[i];
    }
    map<ll, vector<ll>> neighbors;
    for(int i=0;i<n;i++) {
        ll val = pages[i];
        if(i-1>=0 && pages[i-1] != pages[i]) neighbors[val].push_back(pages[i-1]);
        if(i+1<n && pages[i+1] != pages[i]) neighbors[val].push_back(pages[i+1]);
    }
    ll mxsave = 0, sum = 0;
    for(auto& p : neighbors) {
        sort(p.second.begin(), p.second.end());
        ll median = p.second[p.second.size()/2];
        ll val = p.first;
        ll ncost = 0, cost = 0;
        for(ll x : p.second) {
            ncost += abs(median - x);
            cost += abs(val - x);
        }
        mxsave = max(mxsave, cost-ncost);
        sum += cost;
    }
    cout << sum/2 - mxsave;
}
