#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, b, p, f, h, c;
    cin >> t;
    while(t--) {
        cin >> b >> p >> f >> h >> c;
        b/=2;
        // make h the larger one
        if(c>h) {
            swap(h, c);
            swap(p, f);
        }
        int take1 = min(b, p);
        b -= take1;
        int take2 = min(b, f);
        cout << (take1*h + take2*c) << "\n";
    }
}
