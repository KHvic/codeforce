#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n;
    cin >> n;
    pair<int, int> p[n];
    for(int i=0;i<n;i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p+n);
    int res[n];
    for(int i=0;i<n;i++) {
         res[p[i].second] = p[(i+1)%n].first; // each index take next higher
    }
    for(int i=0;i<n;i++) cout << res[i] << " ";
}
