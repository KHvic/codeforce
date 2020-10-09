#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// key observation: for the last building, we should make that height as small as possible
// 1. smaller height allow lessen restriction of future building
// 2. smaller height = less building used, indicating less operations

int main()
{
    fastio
    int n;
    cin >> n;
    vector<int> vals(n+1);
    for(int i=1;i<=n;i++) cin >> vals[i];
    vector<int> dp(n+1), last(n+1); // last => minimum height at i for last building
    for(int i=1;i<=n;i++) {
        int j=i, sum = vals[i];
        // greedy, achieve minimum required sum height for this building & stop
        // can also do binary search on prefix sum
        while(j && sum < last[j-1]) sum += vals[--j];
        dp[i] = dp[j-1] + 1; // number of remaining tower
        last[i] = sum;
    }
    cout << n-dp[n];
}
