#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n;
    cin >> n;
    string res(n, '-');
    for(int i=0;i<n;i++) {
        res[i] = i%4 <= 1 ? 'a' : 'b';
    }
    cout << res;
}
