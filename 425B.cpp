#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// observation: we are trying to build a matrix such that
// for some row/col x, all other rows is totally same as the row or completely different
// i.e Y = X or Y' = flipped(X)

int main()
{
    fastio
    int n, m, k, v;
    cin >> n >> m >> k;
    bitset<105> bs[n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v;
            if(v) bs[i][j] = true;
        }
    }
    // by pigeonhole principle, some rows will be unmodified
    // we fix some rows, and compute the cost
    int res = INT_MAX;
    if(n>k) {
        for(int i=0;i<n;i++) {
            int subres = 0;
            for(int j=0;j<n;j++) {
                bitset<105> diff = bs[i] ^ bs[j];
                int diffCount = diff.count();
                subres += min(diffCount, m-diffCount);
            }
            res = min(subres, res);
        }
    } else {
        // all rows changed, brute force all possibility combinations of bits for any rows
        // since k = 10 >= n, 2^10 = 1024 possibilities
        for(int i=0;i<(1<<n);i++) {
            int subres = 0;
            for(int j=0;j<m;j++) {
                int same = 0;
                for(int k=0;k<n;k++) {
                    if(bs[k][j] == ((i>>k)&1)) same++;
                }
                subres += min(same, n-same);
            }
            res = min(subres, res);
        }
    }
    cout << (res <= k ? res : -1);
}
