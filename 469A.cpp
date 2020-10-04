#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    fastio
    int n, p, v;
    cin >> n;
    vector<bool> can(n+1);
    for(int i=0;i<2;i++) {
        cin >> p;
        while(p--) {
            cin >> v;
            can[v]=1;
        }
    }
    cout << (count(can.begin(), can.end(), 1) == n ? "I become the guy." : "Oh, my keyboard!");
}
