#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n;
    cin >> n;
    vector<int> vals(n);
    int sum = 0;
    for(int i=0;i<n;i++) cin >> vals[i], sum += vals[i];
    int mxgain = -n, cur = 0;
    for(int i=0;i<n;i++) {
        cur += vals[i] == 1 ? -1 : 1;
        cur = max(cur, vals[i] == 1 ? -1 : 1);
        mxgain = max(cur, mxgain);
    }
    cout << mxgain + sum;
}
