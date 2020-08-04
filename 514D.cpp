#include <bits/stdc++.h>
using namespace std;
#define ll long long

// solution one: sliding window with maxqueue O(N)
// solution two: binary search + sparse table max range query O(MlogN)

struct MMQueue {
    deque<vector<int>> mnq, mxq;
    int len = 0;

    void push(int v) {
        len++;
        int c = 1;
        while(!mnq.empty() && v < mnq.back()[0]){
            c += mnq.back()[1];
            mnq.pop_back();
        }
        mnq.push_back({v,c});
        c = 1;
        while(!mxq.empty() && v > mxq.back()[0]){
            c += mxq.back()[1];
            mxq.pop_back();
        }
        mxq.push_back({v,c});
    }
    void pop() {
        len--;
        if(--mnq.front()[1] <=0) mnq.pop_front();
        if(--mxq.front()[1] <=0) mxq.pop_front();
    }
    int min() {
        return mnq.empty() ? 0 : mnq.front()[0];
    }
    int max() {
        return mxq.empty() ? 0 : mxq.front()[0];
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k, a;
    cin >> n >> m >> k;
    vector<MMQueue> q(m);
    auto mxSum = [&]() {
        ll total = 0;
        for(int i=0;i<m;i++) total += q[i].max();
        return total;
    };

    int low=0,high=0;
    ll best = 0;
    vector<int> res(m);
    while(high++<n) {
        for(int i=0;i<m;i++) {
            cin >> a;
            q[i].push(a);
        }
        while(mxSum()>k) {
            low++;
            for(int i=0;i<m;i++) q[i].pop();
        }
        int len = high-low;
        if(len>best) {
            best = len;
            for(int i=0;i<m;i++) res[i] = q[i].max();
        }
    }
    for(int i=0;i<m;i++) {
        if(i) cout << " ";
        cout << res[i];
    }
}
