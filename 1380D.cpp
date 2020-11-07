#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

vector<int> vals, tar;
int n, m, k;
ll x, y;
ll computeMinCost(int low, int high, int side) {
    if(low>high) return 0;
    ll mx = *max_element(vals.begin() + low, vals.begin() + high+1);
    int aboveSide = mx>=side;
    int fireNeed = (aboveSide+k-1)/k;
    int len = high-low+1;
    int remain = len - fireNeed*k;
    if(remain<0) return -1; // not possible
    ll cost = x*fireNeed;
    ll costA = x*(remain/k) + y*(remain%k);
    ll costB = y*remain;
    return cost + min(costA, costB);
}

vector<int> indexes;
bool isSubseq() {
    int i = 0, j = 0;
    while(i<vals.size() && j<tar.size()) {
        if(vals[i] == tar[j]) {
            j++;
            indexes.push_back(i);
        }
        i++;
    }
    return j==tar.size();
}

int main(){
    fastio
    cin >> n >> m;
    cin >> x >> k >> y;
    vals = vector<int>(n+2);
    tar = vector<int>(m+2);
    for(int i=1;i<=n;i++) cin >> vals[i];
    for(int i=1;i<=m;i++) cin >> tar[i];
    bool ok = isSubseq();
    ll res = 0;
    if(ok) {
        for(int i=0;i<indexes.size()-1 && ok;i++) {
            int l = indexes[i], r = indexes[i+1];
            ll sub = computeMinCost(l+1, r-1, max(vals[l], vals[r]));
            res += sub;
            if(sub == -1) ok = false;
        }
    }
    cout << (ok ? res : -1);
}
