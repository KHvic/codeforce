#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n, v;
    cin >> n;
    vector<vector<ll>> dist(n, vector<ll>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> dist[i][j];
    vector<ll> order(n), res(n);
    vector<bool> vis(n);
    for(int i=0;i<n;i++) {
        cin >> order[i];
        order[i]--;
    }
    for(int k=n-1;k>=0;k--) {
        ll sum = 0;
        int realk = order[k];
        vis[realk] = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][realk] + dist[realk][j]);
                if(vis[i] && vis[j]) sum += dist[i][j];
            }
        }
        res[k] = sum;
    }
    for(int i=0;i<n;i++) {
        if(i) cout << " ";
        cout << res[i];
    }
}
