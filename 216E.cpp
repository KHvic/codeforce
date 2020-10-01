#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e6+10;

typedef pair<int, int> pi;
vector<int> right_seg[MAXN];
vector<pi> queries[MAXN];
int ft[MAXN];

int query(int x) {
    int res = 0;
    for(++x;x>0;x-=(x&-x)) res += ft[x];
    return res;
}

int query(int l, int r) {
    return query(r) - query(l-1);
}

void adjust(int x, int v) {
    for(++x;x<MAXN;x+=(x&-x)) ft[x] += v;
}

int main()
{
    fastio
    int n, m, l, r, cnt, v, qidx;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> l >> r;
        right_seg[r].push_back(l);
    }
    for(int i=0;i<m;i++) {
        cin >> cnt;
        vector<int> points;
        points.push_back(0);
        for(int j=0;j<cnt;j++) {
            cin >> v;
            points.push_back(v);
        }
        points.push_back(MAXN-1);
        // reverse question asking how many segments doesn't have any points
        // we want to find all segments in between all points
        for(int j=0;j<points.size()-1;j++) {
            l = points[j]+1, r = points[j+1]-1;
            queries[r].emplace_back(l, i);
        }
    }

    vector<int> res(m, n);
    // handle all right segment queries
    for(int i=0;i<MAXN;i++) {
        for(int l : right_seg[i]) {
            adjust(l, 1);
        }
        for(auto q : queries[i]) {
            tie(l, qidx) = q;
            res[qidx] -=  query(l, i); // query number of segments between l, r
        }
    }
    for(int i=0;i<m;i++) cout << res[i] << "\n";
}
