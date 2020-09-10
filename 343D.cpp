#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// main observation, a vertex is filled only when all child is filled
// question: is there a subchild of this tree that has been emptied?
// using a segment tree we can query whether a child has been emptied
// when we empty a vertex, we denote the vertex
// when we fill a subtree, we first check if any subvertex is emptied, if so set parent to empty
// then color tree segment as filled

int n,q,a,b;
vector<vector<int>> graph;
vector<int> subtree; // denote subtree segment of postorder
vector<int> pars;
unordered_map<int, int> postorderidx; // postorder idx of node x

void postorder(int x, int par=-1) {
    int start_time = subtree.size();
    pars[x] = par;
    for(int u : graph[x]) {
        if(u == par) continue;
        postorder(u, x);
    }
    int idx = subtree.size();
    postorderidx[x] = idx;
    subtree.push_back(start_time);
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
            lazy[idx*2+1] = lazy[idx];
            lazy[idx*2+2] = lazy[idx];
        }
        // update logic
        if(lazy[idx]) {
            segment[idx] = lazy[idx] == -1 ? 0 : (high-low+1);
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
            segment[idx] = segment[idx*2+1] + segment[idx*2+2];
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
    cin >> n;
    graph.assign(n, vector<int>());
    pars.assign(n, -1);
    for(int i=0;i<n-1;i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    postorder(0);
    ST st(n);
    cin >> q;
    for(int t=1;t<=q;t++) {
        cin >> a >> b; b--;
        int idx = postorderidx[b];
        int segment_idx = subtree[idx];
        if(a==1) {
            // fill tree
            int subtree_size = idx - segment_idx + 1;
            int count_filled = st.query(segment_idx, idx);
            // has subvertex not filled, need to inform parent
            if(subtree_size != count_filled && pars[b] != -1) {
                int paridx = postorderidx[pars[b]];
                st.update(paridx, paridx, -1);
            }
            st.update(segment_idx, idx, 1);
        } else if(a==2) {
            // empty tree
            st.update(idx, idx, -1);
        } else {
            int subtree_size = idx - segment_idx + 1;
            int count_filled = st.query(segment_idx, idx);
            cout << (subtree_size == count_filled ? 1 : 0) << "\n";
        }
    }
}
