#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll a, b, n;
    cin >> n;
    while(n--) {
    cin >> a >> b;
    ll diff = abs(a-b);
    ll res = (diff+9)/10;
    cout << res << "\n";
    }
}
