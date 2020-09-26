#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> computeLIS(vector<int>& vals) {
    int n = vals.size();
    vector<int> lis, res(n);
    for(int i=0;i<n;i++) {
        int v = vals[i];
        auto it = lower_bound(lis.begin(), lis.end(), v);
        if(it == lis.end()) {
            lis.push_back(v);
            res[i] = lis.size();
        } else {
            res[i] = it - lis.begin() + 1;
            *it = v;
        }
    }
    return res;
}

int main()
{
    fastio
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];

    vector<int> end_len = computeLIS(vals);
    reverse(vals.begin(), vals.end());
    for(int i=0;i<n;i++) vals[i] = -vals[i];
    vector<int> start_len = computeLIS(vals);
    reverse(start_len.begin(), start_len.end());

    int lis_len = 0;
    for(int i=0;i<n;i++) {
        int len = end_len[i]+start_len[i]-1;
        lis_len = max(lis_len, len);
    }
    vector<int> cnt(lis_len+1);
    for(int i=0;i<n;i++) {
        int len = end_len[i]+start_len[i]-1;
        if(len==lis_len) cnt[end_len[i]]++;
    }

    vector<int> res(n,3);
    for(int i=0;i<n;i++) {
        int len = end_len[i]+start_len[i]-1;
        if(len != lis_len) res[i] = 1; // not a lis
        else if(cnt[end_len[i]] > 1) res[i] = 2; // other lis have this 'depth' too
    }
    for(int i=0;i<n;i++) cout << res[i];
}
