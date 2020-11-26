#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// we can construct a 13377777... to form count(7) subseq of 1337
// but it will go above the length limit 1e9

// if we construct 1333...3337, we form up n*(n-1)/2 subseq
// count of handshake
// greedily construct the second type string then the rest for first type, reduce memory to roughly sqrt(n)

// 133777...733...3333.7

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        string res = "133";
        int cnt3 = 2;
        while((cnt3+1)*cnt3/2 <=n) cnt3++;
        int left = n - cnt3*(cnt3-1)/2;
        for(int i=0;i<left;i++) res += "7";
        for(int i=0;i<cnt3-2;i++) res += "3";
        res += "7\n";
        cout << res;
    }
}
