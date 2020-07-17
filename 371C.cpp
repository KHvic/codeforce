#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string in;
    ll b = 0, s = 0, c = 0;
    ll nb,ns,nc;
    ll c1,c2,c3,r;
    cin >> in;
    cin >> nb >> ns >> nc;
    cin >> c1 >> c2 >> c3 >> r;

    for(char x : in) {
        if(x=='B') b++;
        else if(x=='S') s++;
        else c++;
    }
    ll low = 0, high = r+nb+ns+nc;
    auto canBuy = [&](ll target) {
        ll needB = max(target*b - nb, 0LL);
        ll needS = max(target*s - ns, 0LL);
        ll needC = max(target*c - nc, 0LL);
        ll cost = needB*c1 + needS*c2 + needC*c3;
        return cost <= r;
    };
    while(low<high) {
        ll mid = (low+high)/2+1;
        if(canBuy(mid)) low = mid;
        else high = mid-1;
    }
    cout << low;
}
