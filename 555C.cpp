#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// implicit range update single point query segment tree

struct Node {
    int val;
    Node *l, *r;
    Node(int v):val(v), l(0), r(0) {}
};
 
struct ST {
    Node* root;
    int n;
    const int DEFAULT = 0;
    ST(int n):n(n) {
        root = new Node(DEFAULT);
    }
 
    void update(Node* node, int low, int hi, int qlow, int qhi, int val) {
        if(!node || low>qhi || hi<qlow) return;
        if(low>=qlow && hi<=qhi) {
            node->val = max(val, node->val);
        } else {
            if(!node->l) {
                node->l = new Node(DEFAULT);
                node->r = new Node(DEFAULT);
            }
            int mid = (low+hi) >> 1;
            update(node->l, low, mid, qlow, qhi, val);
            update(node->r, mid+1, hi, qlow, qhi, val);
        }
    }
 
    void update(int qlow, int qhi, int val) {
        update(root, 0, n-1, qlow, qhi, val);
    }
 
    int query(Node* node, int low, int hi, int idx) {
        if(!node || low>idx || hi<idx) return DEFAULT;
        int mid = (low+hi) >> 1;
        return max(max(query(node->l, low, mid, idx), query(node->r, mid+1, hi, idx)), node->val);
    }
 
    int query(int idx) {
        return query(root, 0, n-1, idx);
    }
};
 
 
int main(){
    fastio
    int n, m, x, y;
    char c;
    cin >> n >> m;
    // rowST for tracking rightmost eaten
    // colST for tracking bottommost eaten
    ST rowST(n+1), colST(n+1);
    while(m--) {
        cin >> x >> y >> c;
        if(c=='U') {
            int to = colST.query(x);
            cout << y-to << "\n";
            rowST.update(to+1, y, x);
            colST.update(x, x, y);
        } else {
            int to = rowST.query(y);
            cout << x-to << "\n";
            colST.update(to+1, x, y);
            rowST.update(y, y, x);
        }
    }
}
