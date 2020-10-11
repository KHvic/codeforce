#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// observation:
// when we round down => -x
// when we round up => 1-x
// thus total operation => res = (total-rounddown) + (total-roundup) = N - sumx
// need to handle special case of 0 fractional, select some amount of 0 for round down
// subtract res-num_zero_roundup (since round up for 0 is still 0)

int main()
{
    fastio
    int n;
    cin >> n;
    int zero = 0;
    double sum = 0, v;
    for(int i=0;i<2*n;i++) {
        cin >> v;
        v -= floor(v);
        sum += v;
        if(v == 0) {
            zero++;
        }
    }
    double res = n - sum;
    double reswithzero = abs(res);
    for(int i=0;i<=min(n, zero);i++) {
        reswithzero = min(abs(res-i), reswithzero);
    }
    cout << fixed << setprecision(3) << reswithzero;
}
