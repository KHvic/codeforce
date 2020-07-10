#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    bool isEven = k>(n+1)/2;
    if(isEven) {
        k -= (n+1)/2;
        cout << 2LL*(k);
    } else {
        cout << 1LL+2*(k-1);
    }
}
