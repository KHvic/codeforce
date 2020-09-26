#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n, s, l;
    cin >> n >> s >> l;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    vector<int> dp(n+1, 1e6);
    dp[0] = 0;
    deque<int> mnq, mxq, q;
    q.push_back(-1); // position of all valid vals[0:i]
    for(int i=0;i<n;i++) {
        while(!mnq.empty() && vals[i] <= vals[mnq.back()]) mnq.pop_back();
        while(!mxq.empty() && vals[i] >= vals[mxq.back()]) mxq.pop_back();
        mxq.push_back(i);
        mnq.push_back(i);
        // check validity of q
        while(!q.empty() && i-q.front() >= l) {
            int pos = q.front()+1;
            while(!mnq.empty() && mnq.front() < pos) mnq.pop_front();
            while(!mxq.empty() && mxq.front() < pos) mxq.pop_front();
            int mx = vals[mxq.front()], mn = vals[mnq.front()];
            if(mx-mn > s) q.pop_front(); // not valid, pop
            else {
                dp[i+1] = dp[q.front()+1] + 1;
                q.push_back(i);
                break;
            }
        }
    }
    cout << (dp[n]>n?-1 : dp[n]);
}
