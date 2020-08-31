#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<ll,ll> pii;
int main(){
    fastio
    ll a, b;
    string s;
    cin >> a >> b >> s;

    ll x=0,y=0;
    set<pii> seen;
    for(char c : s) {
        seen.insert({x,y});
        switch(c) {
            case 'U': y++; break;
            case 'D': y--; break;
            case 'L': x--; break;
            case 'R': x++; break;
        }
    }
    for(auto& p : seen) {
        ll dx = a-p.first, dy = b-p.second;
        bool ok = false;
        // some condition to consider, when dx or dy is 0
        // dx/x must be positive, same for dy/y
        // if both are not 0, the number of iteration between them must be the same dx/x == dy/y
        // when either dx or dy is 0, x or y have to be zero
        if(dx==0 && dy==0) ok = true;
        else if((dx==0&&x==0) && (y!=0 && dy%y==0 && dy/y > 0)) ok = true;
        else if((dy==0&&y==0) && (x!=0 && dx%x==0 && dx/x > 0)) ok = true;
        else if(x!=0 && y!=0 && (dx%x==0)&&(dy%y==0) && dx/x == dy/y && dx/x > 0) ok = true;
        if(ok) {
            cout << "Yes"; return 0;
        }
    }
    cout << "No";
}
