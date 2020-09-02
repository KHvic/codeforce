#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// idea: given two probability
// it is always better to include the item with larger probability
// this can be shown mathematically be considering the change of probability after adding some item x to some current subset
// therefore, we greedily pick some suffix with largest probability

int main(){
    fastio
    int n;
    cin >> n;
    vector<double> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    sort(vals.begin(), vals.end(), greater<double>());

    // probability = p1*(1-p2)...+p2*(1-p1)... = product(1-p for all p)*sum(p/(1-p)  for all p)
    double sum = 0, product = 1;
    double res = 0;
    for(double p : vals) {
        if(p==1) {
            res = 1; break;
        }
        sum += (p/(1.0-p));
        product *= (1.0-p);
        res = max(sum*product, res);
    }
    cout << fixed << setprecision(12) << res;
}
