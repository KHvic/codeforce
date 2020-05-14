#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& bucket) {
    int res = bucket.size();
    vector<int> dp(bucket.size());

    for(int i=0;i<bucket.size();i++) {
        int itemOnright = bucket.size()-i-1;
        int missing = i==0 ? 0 : bucket[i]-bucket[i-1]-1;
        int costAdd = i==0 ? 0 : missing + dp[i-1];
        int costIgnore = i==0 ? 0 : i;
        dp[i] = min(costAdd, costIgnore);
        res = min(res, dp[i] + itemOnright);
    }

    return res;
}

int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        string in;
        cin >> in;
        vector<vector<int>> buckets(k);
        int total = 0;
        for(int i=0;i<n;i++) {
            if(in[i] == '1') {
                total++;
                buckets[i%k].push_back(i/k);
            }
        }
        int best = total;
        for(auto& p : buckets) {
            int cost = solve(p) + (total-p.size());
            best = min(best, cost);
        }
        printf("%d\n", best);
    }
}
