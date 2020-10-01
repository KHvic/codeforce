#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n;
    cin >> n;
    int cur = 0, energy = 0, res = 0;
    for(int i=0,v;i<n;i++) {
        cin >> v;
        int diff = v - cur;
        energy -= diff;
        if(energy<0) {
            res -= energy;
            energy = 0;
        }
        cur = v;
    }
    cout << res;
}
