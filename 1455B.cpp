#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, x;
    cin >> t;
    while(t--) {
        cin >> x;
        // say we have S = n*(n+1)/2 >= x
        // extraSteps = S - x
        // just change some number (extraSteps-1) to -1 which reduce exactly extraSteps amount
        // edgecase: extraSteps = 1, since there isn't a 0 step, we add one
        int n = sqrt(x);
        while(n*(n+1)/2 < x) n++;
        if(n*(n+1)/2 - x == 1) n++;
        cout << n << "\n";
    }
}
