#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int low = 1, high = n*n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n/2;j++) {
            if(j) cout << " ";
            cout << low++ << " " << high--;
        }
        cout << "\n";
    }
}
