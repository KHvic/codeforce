#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

vector<int> vals, tmp;
int n, len, m, q;
vector<ll> depthInversion, depthIncrease;


void merging(int low, int high, int d) {
    ll inv = 0, inc = 0;
    int mid = (low+high) >> 1;
    int p1 = low, p2 = mid+1;
    int idx = low;
    while(p1<=mid || p2<=high) {
        if(p1>mid || (p2<=high && vals[p1] > vals[p2])) {
            tmp[idx] = vals[p2++];
            depthInversion[d] += mid-p1+1;
        } else tmp[idx] = vals[p1++];
        idx++;
    }
    p1 = low, p2 = mid+1;
    while(p1<=mid || p2<=high) {
        if(p2>high || (p1<=mid && vals[p1] < vals[p2])) {
            depthIncrease[d] += high-p2+1;
            p1++;
        } else p2++;
    }
    for(int i=low;i<=high;i++) vals[i] = tmp[i];
}

void mergesort(int low, int high, int depth=0) {
    if(low>=high) return;
    int mid = (low+high) >> 1;
    mergesort(low, mid, depth-1), mergesort(mid+1, high, depth-1);

    merging(low, high, depth);
}

int main()
{
    fastio
    cin >> n;
    depthIncrease = depthInversion = vector<ll>(n+1);
    len = 1<<n;
    tmp = vals = vector<int>(len);
    for(int i=0;i<len;i++) cin >> vals[i];

    mergesort(0, len-1, n);
    cin >> m;
    while(m--) {
        cin >> q;
        for(int i=0;i<=q;i++) swap(depthIncrease[i], depthInversion[i]);
        ll total = 0;
        for(int i=0;i<=n;i++) total += depthInversion[i];
        cout << total << "\n";
    }
}
