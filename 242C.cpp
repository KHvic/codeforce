#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int,int> pii;

int main(){
    fastio
    int x,x2,y,y2,a,b,r;
    cin >> x >> y >> x2 >> y2;
    int n;
    cin >> n;
    set<pii> allowed;
    for(int i=0;i<n;i++) {
        cin >> r >> a >> b;
        for(int j=a;j<=b;j++) allowed.insert({r,j});
    }
    map<pii, int> dist;
    queue<pii> q;
    q.push({x,y});
    dist[q.front()] = 0;
    while(!q.empty()) {
        int d = dist[q.front()];
        tie(x,y) = q.front(); q.pop();
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++) {
            int nx=x+i, ny=y+j;
            pii nxt = {nx, ny};
            if(allowed.count(nxt) && !dist.count(nxt)){
                dist[nxt] = d+1;
                q.push(nxt);
            }
        }
    }
    if(dist.count({x2,y2})) cout << dist[{x2,y2}];
    else cout << -1;
}
