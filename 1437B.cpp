#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// observation: each time we can swap some 00 with another 11 to resolve adjacency
// thus the answer is bounded by max(adjZero, adjOne)

int main(){
    fastio
    int t,n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int zero = 0, one = 0;//count consecutive
        for(int i=1;i<n;i++) {
            if(s[i] == s[i-1]) (s[i]=='0' ? zero : one)++;
        }
        cout << max(zero, one) << "\n";
    }
}
