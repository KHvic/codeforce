#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n,a,b;
    cin >> n;
    int res = 1e9;
    map<int, int> cnt1, cnt2;
    int required = (n+1)/2;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        cnt1[a]++;
        if(a!=b) {
            cnt2[b]++;
            cnt1[b];
        }
    }
    for(auto& p : cnt1) {
        int val = p.first;
        int front = p.second, back = cnt2[val];
        if(front+back >= required) {
            int need = max(required - front, 0);
            res = min(res, need);
        }
    }
    cout << (res >= 1e9 ? -1 : res) << "\n";
}
