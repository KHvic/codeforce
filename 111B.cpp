#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int MAXN = 1e5+5;
int lastpos[MAXN];

int main(){
    fastio
    int n, x, y;
    cin >> n;


    for(int i=1;i<=n;i++) {
        cin >> x >> y;
        int res = 0;
        for(ll j=1;j*j<=x;j++) {
            if(x%j) continue;
            if(i-lastpos[j] > y) res++;
            int inv = x/j;
            if(inv != j && i-lastpos[inv] > y) {
                res++;
            }
        }
        for(ll j=1;j*j<=x;j++) {
            if(x%j) continue;
            lastpos[j] = lastpos[x/j] = i;
        }
        cout << res << "\n";
    }
}
