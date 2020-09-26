#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef tuple<int, int, int> ti;

int main()
{
    fastio
    int n,m;
    int d,a,b,t;
    cin >> n >> m >> d;
    vector<ti> fw;
    fw.reserve(m);
    for(int i=0;i<m;i++) {
        cin >> a >> b >> t; a--;
        fw.emplace_back(t, a, b);
    }
    vector<vector<ll>> dp(2, vector<ll>(n));
    int t1 = 0;
    int idx = 0;
    for(auto& f : fw) {
        tie(t,a,b) = f;
        ll time = t-t1;
        deque<int> mxq;
        for(int i=0,j=0;i<n;i++) {
            while(!mxq.empty() && i-mxq.front()>d*time) mxq.pop_front();
            while(j<n && j-i<=d*time) {
                ll v = dp[1-idx][j];
                while(!mxq.empty() && v >= dp[1-idx][mxq.back()]) mxq.pop_back();
                mxq.push_back(j++);
            }
            dp[idx][i] = dp[1-idx][mxq.front()] + (ll)(b - abs(i-a));
        }
        t1 = t;
        idx = 1-idx;
    }
    cout << *max_element(dp[1-idx].begin(), dp[1-idx].end());
}
