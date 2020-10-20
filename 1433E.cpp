#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

ll fac[21];
void init() {
    fac[0] = 1;
    for(int i=1;i<=20;i++) fac[i] = fac[i-1]*i;
}

int main(){
    fastio
    init();
    int t,n,v;
    cin >> n;
    for(int i=0;i<n/2;i++) pat.push_back(i);
    ll ways = fac[n/2 - 1];
    ll choice = fac[n]/fac[n/2]/(fac[n/2])/2;
    choice *= ways*ways;
    cout << choice;
}
