#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n, l, r, m;
    string s;
    cin >> s;
    n = s.size();
    vector<int> psum(n+1, 0);
    for(int i=0;i<n-1;i++)
        if(s[i] == s[i+1])
            psum[i+1] = 1;
    for(int i=1;i<=n;i++) psum[i] += psum[i-1];
    function<int(int,int)> range = [&](int lo, int hi) -> int {
        return psum[hi] - psum[lo];
    };

    cin >> m;
    while(m--) {
        cin >> l >> r; l--; r--;
        cout << range(l, r) << "\n";
    }
}
