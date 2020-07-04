#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t, a, b, n, m;
    cin >> t;
    while(t--) {
        cin >> a >> b >> n >> m;
        if(a>b) swap(a, b); // a be the smaller cookies
        // key observation: type 1 guest will be angry only when there's no cookies left
        // type 2 guest will be angry (min(a,b) < m), not enough smaller count cookies
        
        // we focus on type 2 guests being first (m)
        // it is better for all type 1 guests to go later
        // this is because type 2 guests always take smaller count cookies
        // if type 1 guests come first, they could unnecessary reduce smaller count cookies
        // first condition: check if enough smaller count cookies for type 2 guests
        // second condition: enough cookies in total for all guests
        if(a<m || (a+b)<(n+m)) cout << "No" << "\n";
        else cout << "Yes" << "\n";
    }
}
