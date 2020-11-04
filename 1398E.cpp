#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

struct cmp {
    bool operator()(const ll a, const ll b) const {
        return a < b;
    }
};

set<ll> special;
vector<int> specialCnt = {0, 0};

struct TopK {
    int k;
    multiset<ll, cmp> high, low;
    vector<ll> sum = {0, 0};
    TopK(int k=0):k(k) {}

    void adjust() {
        while(high.size() > k) {
            auto rmv = high.begin();
            low.insert(*rmv);
            high.erase(rmv);
            sum[0] -= *rmv;
            sum[1] += *rmv;

            bool isSpecial = special.count(*rmv);
            specialCnt[0] -= isSpecial;
            specialCnt[1] += isSpecial;
        }
        while(high.size() < k && !low.empty()) {
            auto rmv = low.rbegin();
            ll val = *rmv;
            high.insert(*rmv);
            low.erase(next(rmv).base());
            sum[1] -= val;
            sum[0] += val;

            bool isSpecial = special.count(val);
            specialCnt[1] -= isSpecial;
            specialCnt[0] += isSpecial;
        }
    }

    void add(ll x) {
        high.insert(x);
        sum[0] += x;
        if(special.count(x)) specialCnt[0]++;
        adjust();
    }

    void del(ll x) {
        bool isSpecial = special.count(x);
        if(high.count(x)) high.erase(high.find(x)), specialCnt[0] -= isSpecial, sum[0] -= x;
        else low.erase(low.find(x)), specialCnt[1] -= isSpecial, sum[1] -= x;
        adjust();
    }

    void setK(int k) {
        this->k = k;
        adjust();
    }

    int size() {
        return high.size() + low.size();
    }
};


int main(){
    fastio
    int n, t, x;
    cin >> n;
    TopK top;
    for(int i=0;i<n;i++) {
        cin >> t >> x;
        if(x>0) {
            // add
            if(t) {
                special.insert(x);
                top.setK(top.k+1);
            }
            top.add(x);
        } else {
            x = -x;
            // delete
            top.del(x);
            if(t) {
                special.erase(x);
                top.setK(top.k-1);
            }
        }

        ll sumTopK = top.sum[0]*2LL, sumRest = top.sum[1];
        // check if we can apply all k lightning spells on top k items
        if(specialCnt[0] == top.k && top.k != 0) {
            sumTopK -= *top.high.begin();
            if(top.low.size()) sumTopK += *top.low.rbegin(); // apply to next possible instead
        }
        cout << (sumTopK + sumRest) << "\n";
    }
}
