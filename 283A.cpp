#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,o,v1,v2;
    cin >> n;
    vector<ll> vals(1,0); // initial
    vector<ll> add(1,0);
    ll sum = 0;
    while(n--) {
        cin >> o;
        if(o==1) {
            cin >> v1 >> v2;
            // add v2 to first v1
            sum += v1*v2;
            add[v1-1] += v2;
        } else if(o==2) {
            cin >> v1;
            vals.push_back(v1);
            add.push_back(0);
            sum += v1;
        } else {
            sum -= vals.back();vals.pop_back();
            sum -= add.back();
            if(add.size()-2>=0) add[add.size()-2] += add.back();
            add.pop_back();
        }
        printf("%.10f\n", (1.0*sum)/vals.size());
    }
}
