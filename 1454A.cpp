#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0;i<n;i++) cout << ((i+1)%n)+1 << " \n"[i==n-1];
    }
}
