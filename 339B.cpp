#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,a;
    cin >> n >> m;
    typedef long long ll;
    ll res = 0;
    int cur = 0;
    for(int i=0;i<m;i++) {
        cin >> a; a--;
        int dist = 0;
        if(a<cur) {
            dist = n - cur + a;
        } else dist = a-cur;
        res += dist;
        cur = a;
    }
    cout << res;
}
