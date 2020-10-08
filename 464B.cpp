#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

vector<ll> points[8];

bool dfs(int idx) {
    if(idx==8) {
        map<ll, int> cnt;
        for(int i=0;i<8;i++) {
            for(int j=i+1;j<8;j++) {
                ll dx = points[i][0] - points[j][0];
                ll dy = points[i][1] - points[j][1];
                ll dz = points[i][2] - points[j][2];
                ll len = dx*dx + dy*dy + dz*dz;
                cnt[len]++;
            }
        }
        ll mn = cnt.begin()->first;
        return cnt[mn] == 12 && cnt[3*mn] == 4 && cnt[2*mn] == 12;
    } else {
        do {
            if(dfs(idx+1)) return true;
        } while(next_permutation(points[idx].begin(), points[idx].end()));
    }
    return false;
}

int main()
{
    fastio
    ll a, b, c;
    for(int i=0;i<8;i++) {
        cin >> a >> b >> c;
        points[i] = {a, b, c};
        sort(points[i].begin(), points[i].end());
    }
    // observation: we can fix the first point
    if(dfs(1)) { // start from second point
        cout << "YES\n";
        for(int i=0;i<8;i++)
            cout << points[i][0] << " " << points[i][1] << " " << points[i][2] << "\n";
    } else cout << "NO\n";
}
