#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<int>> graph;
vector<int> subtree;
vector<int> depth;
unordered_map<int, int> postorderidx;

void dfs(int x, int par, int d=0) {
    int start = subtree.size();
    for(int u : graph[x]) {
        if(par == u) continue;
        dfs(u, x, d+1);
    }
    postorderidx[x] = subtree.size();
    subtree.push_back(start);
    depth.push_back(d);
}

struct ST {
    int n;
    vector<int> segment, lazy;
    ST(int len):n(len){
        segment.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void updateLazy(int idx, int low, int high) {
        if(lazy[idx] && low != high) {
            lazy[idx*2+1] += lazy[idx];
            lazy[idx*2+2] += lazy[idx];
        }
        // update logic
        if(lazy[idx]) {
            if(low==high) {
                segment[idx] += lazy[idx];
            }
        }
        lazy[idx] = 0;
    }

    void update(int idx, int low, int hi, int qlow, int qhi, int val) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return;
        else if(low>=qlow && hi<=qhi) {
            lazy[idx] = val;
            updateLazy(idx, low, hi);
        } else {
            int mid = (low+hi) >> 1;
            update(idx*2+1, low, mid, qlow, qhi, val);
            update(idx*2+2, mid+1, hi, qlow, qhi, val);
        }
    }

    void update(int qlow, int qhi, int val) {
        update(0, 0, n-1, qlow, qhi, val);
    }

    int query(int idx, int low, int hi, int qlow, int qhi) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return 0;
        else if(low>=qlow && hi<=qhi) return segment[idx];
        int mid = (low+hi) >> 1;
        return query(idx*2+1, low, mid, qlow, qhi) + query(idx*2+2, mid+1, hi, qlow, qhi);
    }

    int query(int qlow, int qhi) {
        return query(0, 0, n-1, qlow, qhi);
    }
};


int main(){
    fastio
    int n,m,u,v;
    cin >> n >> m;
    graph.assign(n, vector<int>());
    vector<int> vals(n);
    for(int i=0;i<n;i++) {
        cin >> vals[i];
    }
    for(int i=0;i<n-1;i++) {
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, -1);
    ST st(n);
    for(int i=0;i<n;i++) {
        int idx = postorderidx[i];
        int d = depth[idx];
        st.update(idx, idx, (d%2 ? -1 : 1)*vals[i]);
    }
    while(m--) {
        cin >> u >> v; v--;
        int idx = postorderidx[v];
        int d = depth[idx];
        if(u==1) {
            cin >> u;
            int segment = subtree[idx];
            st.update(segment, idx, (d%2?-1:1)*u);
        } else {
            int res = (d%2 ? -1 : 1) * st.query(idx, idx);
            cout << res << "\n";
        }
    }
}
