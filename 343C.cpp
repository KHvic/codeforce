#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main()
{
    fastio
    int n,m;
    cin >> n >> m;
    vector<ll> h(n), t(m);
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<m;i++) cin >> t[i];
    auto cost = [&](int low, int high, int pos) {
        return t[high] - t[low] + min(abs(h[pos]-t[high]), abs(h[pos]-t[low]));
    };
    auto can = [&](ll target) {
        int j = 0;
        for(int i=0;i<n&&j<m;i++) {
            int k = j-1;
            while(k+1<m && cost(j, k+1, i) <= target) k++;
            j = k+1;
        }
        return j >= m;
    };
    ll low = 0, high = 1e13;
    while(low<high) {
        ll mid = (low+high) >> 1;
        if(can(mid)) high = mid;
        else low = mid+1;
    }
    cout << low;
}
