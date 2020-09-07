#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

class FenwickTree {
private: vector<ll> ft;
public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
    ll rsq(int b) {
        b++;
        ll sum = 0;
        while(b>0) {
            sum += ft[b];
            b -= (b&-b);
        }
        return sum;
    }
    ll rsq(int a, int b) {
        return rsq(b) - rsq(a-1);
    }
    void adjust(int k, ll v) {
        k++;
        while(k<ft.size()) {
            ft[k] += v;
            k += (k&-k);
        }
    }
};

int main(){
    fastio
    int len;
    cin >> len;
    vector<int> vals(len), sorted(len);
    for(int i=0;i<len;i++) {
        cin >> vals[i];
        sorted[i] = vals[i];
    }

    FenwickTree right(len), left(len);
    sort(sorted.begin(), sorted.end());
    map<int,int> idx;
    for(int i=0;i<len;i++) {
        idx[sorted[i]] = i;
        right.adjust(i, 1);
    }

    ll res = 0;
    for(int i=0;i<len;i++) {
        int v = idx[vals[i]];
        right.adjust(v, -1);
        ll l = left.rsq(v, len-1), r = right.rsq(v);
        res += l * r;
        left.adjust(v, 1);
    }
    cout << res;
}
