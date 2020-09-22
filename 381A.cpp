#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n; cin >> n;
    deque<int> q(n);
    for(int i=0;i<n;i++) cin >> q[i];
    int a=0, b=0, turn=0;
    while(!q.empty()) {
        int l = q.front(), r = q.back();
        int mx = max(l, r);
        if(turn) b += mx;
        else a += mx;
        if(l==mx) q.pop_front();
        else q.pop_back();
        turn ^= 1;
    }
    cout << a << " " << b;
}
