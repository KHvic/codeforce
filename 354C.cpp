#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// key observation: trying to find the highest number d, such that all A % d <= k
// case 1: when minA <= k+1, all A % minA <= k, thus answer is minA
// case 2: minA > k+1, brute force all possible d from 1 to minA

// foreach d, check count of number lying between range of d..(d+k), d*2..(d*2+k), ... maxA/d..(maxA/d+k)
// that is count such that A % d <= k
// harmonic series time complexity with at most N 'd', NlogN

const int MAXN = 2*1e6;
int cnt[MAXN];

int main()
{
    fastio
    int n, k, v;
    cin >> n >> k;
    int mx = -1e9, mn = 1e9;
    for(int i=0;i<n;i++) {
        cin >> v;
        cnt[v]++;
        mx = max(mx, v), mn = min(mn, v);
    }
    if(mn <= k+1) {
        cout << mn; return 0;
    }
    auto range = [&](int low, int high) {
        return cnt[high] - cnt[low-1];
    };
    for(int i=mn;i<=mx+k;i++) cnt[i] += cnt[i-1];
    for(int d=mn;d>=k+1;d--) {
        int cnt = 0;
        for(int d2=d;d2<=mx;d2+=d) {
            cnt += range(d2, d2+k);
        }
        if(cnt == n) {
            cout << d; return 0;
        }
    }
    // should not reach here
}
