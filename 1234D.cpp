#include <bits/stdc++.h>
 
using namespace std;
string str;
int t, n;
 
vector<int> segmentTree;
 
void build() {
    n = str.size();
    segmentTree.assign(n*2, 0);
    for(int i=0;i<n;i++) {
        int idx = str[i] - 'a';
        segmentTree[n+i] = 1<<idx;
    }
    for(int i=n-1;i>0;i--) {
        segmentTree[i] = segmentTree[i*2] | segmentTree[i*2+1];
    }
}
 
void update(int p, char val){
    int idx = val-'a';
    segmentTree[n+p] = 1<<idx;
    for(p=(n+p)>>1;p>0;p>>=1)
        segmentTree[p] = segmentTree[p*2] | segmentTree[p*2+1];
}
 
int query(int l, int r){
    int res = 0;
    for(l+=n, r+=n; l<=r; l>>=1, r>>=1) {
        if((l&1) == 1) res |= segmentTree[l++];
        if((r&1) == 0) res |= segmentTree[r--];
    }
    return res;
}
 
int main() {
    int type, l, r, pos;
    char c;
    cin >> str >> t;
    build();
    for(int i=0;i<t;i++){
        cin >> type;
        if(type == 1) {
            cin >> pos >> c;
            update(pos-1, c);
        } else if(type == 2) {
            cin >> l >> r;
            int res = query(l-1, r-1);
            int numBits = 0;
            while(res) {
                numBits++;
                res &= (res-1);
            }
            printf("%d\n", numBits);
        }
    }
}