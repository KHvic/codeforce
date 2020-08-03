#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int,ll> d1, d2;
    vector<vector<ll>> vals(n,vector<ll>(n));
    ll mx1 = -1, mx2 = -1;
    int x1,x2,y1,y2;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> vals[i][j];
            d1[i+j]+=vals[i][j]; d2[i-j]+=vals[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ll val = d1[i+j] + d2[i-j] - vals[i][j];
            bool odd = (i+j)%2;
            if(odd && val > mx1) {
                mx1 = val;
                x1 = i; y1 = j;
            }
            if(!odd && val > mx2) {
                mx2 = val;
                x2 = i; y2 = j;
            }
        }
    }
    cout << mx1+mx2 << "\n";
    cout << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1;
}
