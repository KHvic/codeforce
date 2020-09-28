#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);


// let dp[i] = min_cost to reduce b+i to b
// main observation: dp[i] is monotonically increasing
// if we subtract 1, dp[i] = dp[i-1] +1
// otherwise:
// notice i - i%x = (i-1) - (i-1)%x
// thus dp[i] = 1 + dp[i - i%x], then dp[i] >= dp[i-1], since dp[i-1] can also reach dp[i-i%x] but might not be the most optimal transition here for dp[i-1]
// problem is thus reduced to greedy, selecting the smallest number i can reduce to with any x

// second main observation:
// 1. when we do i-(i-%x), we reduce to a smallest number A that is divisible by some x (used to reach A)
// 2. we can do a -1 to this A, resulting in A-1
// 3. finally, we can reduce this A to the next smallest number that is divisible the same x again
// essentially we can reduce A by MAX(X) in O(1) time

int main()
{
    fastio
    int n, v;
    cin >> n;
    set<int> vals;
    for(int i=0;i<n;i++) {
        cin >> v;
        vals.insert(v);
    }
    int a,b;
    cin >> a >> b;
    int cost = 0;
    while(a>b) {
        cost++;
        int best_a = a-1;
        vector<int> to_remove;
        for(int x : vals) {
            int next_a = a - (a%x);
            if(next_a<b) {
                to_remove.push_back(x);
            } else best_a = min(best_a, next_a);
        }
        for(int x : to_remove) vals.erase(x);
        a = best_a;
    }
    cout << cost;
}
