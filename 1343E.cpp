#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t,n,m,a,b,c,v1,v2;
vector<vector<int>> graph;

vector<int> bfs(int a) {
    vector<int> dist(n,1e7);
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    int steps = 1;
    while(!q.empty()) {
        for(int i=q.size();i>0;i--) {
            int cur = q.front(); q.pop();
            for(int next : graph[cur]) {
                if(steps >= dist[next]) continue;
                dist[next] = steps;
                q.push(next);
            }
        }
        steps++;
    }
    return dist;
}

int main(){
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d %d %d",&n,&m,&a,&b,&c);
        a--; b--; c--;
        graph.assign(n,vector<int>());
        vector<ll> edgeWeight;
        for(int i=0;i<m;i++) {
            scanf("%d",&v1);
            edgeWeight.push_back(v1);
        }

        for(int i=0;i<m;i++) {
            scanf("%d %d",&v1,&v2);
            v1--; v2--;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        vector<int> shortestA = bfs(a);
        vector<int> shortestB = bfs(b);
        vector<int> shortestC = bfs(c);

        // minimum prefix sum on edgeWeight
        edgeWeight.push_back(0); // when 0 edge required
        sort(edgeWeight.begin(), edgeWeight.end());
        for(int i=1;i<=m;i++) edgeWeight[i] += edgeWeight[i-1];

        // try all pivot such that a->p->b->p->c
        // p can either a,b,c as well
        ll best = 1e18;
        for(int i=0;i<n;i++) {
            ll costB = edgeWeight[shortestB[i]]; // B to p twice
            int totalEdges = shortestB[i] + shortestA[i] + shortestC[i];
            if(totalEdges > m) continue; // too many edges needed
            ll costABC = edgeWeight[totalEdges];
            best = min(best, costB + costABC);
        }
        printf("%lld\n", best);
    }
}
