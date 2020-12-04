#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if((i+j)%2) cout << "B";
            else cout << "W";
        }
        cout << "\n";
    }
}
