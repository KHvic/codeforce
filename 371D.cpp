#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> waterAdded, capacity;
set<int> not_full;
int n, m, o, p;
ll x;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    capacity.assign(n,0); waterAdded.assign(n,0);
    for(int i=0;i<n;i++) {
        cin >> capacity[i];
        not_full.insert(i);
    }
    cin >> m;
    while(m--) {
        cin >> o;
        if(o==1) {
            cin >> p >> x; p--;
            auto it = not_full.lower_bound(p);
            while(x && it != not_full.end()) {
                p = *it;
                ll take = min(x, capacity[p] - waterAdded[p]);
                waterAdded[p] += take;
                x -= take;
                it++;
                if(waterAdded[p] == capacity[p]) {
                    not_full.erase(p);
                }
            }
        } else {
            cin >> p;p--;
            cout << waterAdded[p] << "\n";
        }
    }
}
