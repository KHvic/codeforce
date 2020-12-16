#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n;
    cin >> n;
    vector<int> vals(n);
    int gcd = 0;
    for(int i=0;i<n;i++) cin >> vals[i], gcd = __gcd(gcd, vals[i]);
    if(vals[0] != gcd) {
        cout << -1;
    } else {
        cout << n*2 << "\n";
        for(int i=0;i<n;i++)
            cout << vals[i] << " " << gcd << " ";
    }
}
