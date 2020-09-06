#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// a[i] & a[i+1] condition is connected by an edge, thus at most n-1 edges
// item a[i] = u, a[i+1] = v
// given k coupon, we have k vertex
// condition 1: each vertex need to be directly connected to other vertices, thus we need (k-1)*k/2
// condition 2: graph has to be semi-eulerian (at most 2 odd degree vertex)
// why? so that all required condition is covered by starting from any vertex

// for condition 2:
// case 1: k is odd, then each vertex has an even degree (already an eulerian graph)
// case 2: k is even, each vertex has an odd degree, we need to reduce until only 2 vertex has odd degree
// adding an edge between 2 odd degree vertex by k/2 - 1 times

int main(){
    fastio
    int n,m,a;
    cin >> n >> m;
    vector<int> cost(m);
    for(int i=0;i<m;i++) cin >> a >> cost[i];
    // greedy choose higher cost
    sort(cost.begin(), cost.end(), greater<int>());

    int k = 1;
    // can do binary search to make it faster
    while(true) {
        int nxtk = k+1;
        int need = nxtk*(nxtk-1)/2;
        if(nxtk % 2 == 0) need += nxtk/2 - 1;
        if(need <= (n-1) && nxtk <= m) k = nxtk;
        else break;
    }
    ll res = 0;
    for(int i=0;i<k;i++) res += cost[i];
    cout << res;
}
