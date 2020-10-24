#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// square decomposition, count frequency of number k in some range
struct SD{
    const static int MAX = 1e5+5;
    int len, n;
    vector<vector<int>> cnt;
    vector<deque<int>> vals;
    SD(deque<int>& v):n(v.size()) {
        len = sqrt(v.size()) + 1;
        cnt = vector<vector<int>>(len, vector<int>(MAX));
        vals.assign(len, deque<int>());
        for(int i=0;i<n;i++) {
            cnt[i/len][v[i]]++;
            vals[i/len].push_back(v[i]);
        }
    }

    int query(int l, int r, int k) {
        int res = 0;
        int blockL = l/len, blockR = r/len;
        if(blockL == blockR) {
            for(int i=l;i<=r;i++) res += get(i) == k;
        } else {
            for(int i=l;i<(blockL+1)*len;i++) res += get(i) == k;
            for(int i=blockL+1;i<blockR;i++) res += cnt[i][k];
            for(int i=blockR*len;i<=r;i++) res += get(i) == k;
        }
        return res;
    }

    int get(int idx) {
        int b = idx/len, offset = idx%len;
        return vals[b][offset];
    }
    // perform cyclic shift in O(sqrtN)
    void shift(int l, int r) {
        int rVal = get(r);
        int blockL = l/len, blockR = r/len;
        int offsetL = l%len, offsetR = r%len;
        vals[blockR].erase(vals[blockR].begin() + offsetR);
        cnt[blockR][rVal]--;
        vals[blockL].insert(vals[blockL].begin() + offsetL, rVal);
        cnt[blockL][rVal]++;
        for(int i=blockL;i<blockR;i++) {
            int last = vals[i].back(); vals[i].pop_back();
            cnt[i][last]--;
            vals[i+1].push_front(last);
            cnt[i+1][last]++;
        }
    }
};

int main(){
    fastio
    int n, q, t, l, r, k;
    cin >> n;
    deque<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    SD sd(vals);
    cin >> q;
    int lastans = 0;
    while(q--) {
        cin >> t >> l >> r;
        l = (l+lastans-1)%n;
        r = (r+lastans-1)%n;
        if(l>r) swap(l, r);
        if(t==1) {
            sd.shift(l, r);
        } else {
            cin >> k;
            k = (k+lastans-1)%n + 1;
            lastans = sd.query(l, r, k);
            cout << lastans << "\n";
        }
    }
}
