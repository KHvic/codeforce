#include<bits/stdc++.h>
using namespace std;
#define ll long long
// idea: first bit from left where l[i] != r[i]
// then ans is to set (1<<(i+1)) - 1
// reason is because all remaining bits can be set somehow by choosing 0 for one number and 1 for another number
// since a = 0xxxxx to b = 1yyyyy, we have few cases
 
// let's take a look at the second bit
// 1. a = 00, b = 10 => can just change a to 01 < b = 10 
// 2. a = 00, b = 11 => already set for second bit
// 3. a = 01, b = 10 => already set for second bit
// 4. a = 01, b = 11 => can just change b to 10 > a = 01
// thus, we can always set all bits

ll solveBits(ll l, ll r) {
    for(int i=62;i>=0;i--) {
        ll b1 = l & (1LL<<i);
        ll b2 = r & (1LL<<i);
        if(b1 != b2) return (1LL<<(i+1)) - 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll l,r;
    cin >> l >> r;
    cout << solveBits(l, r);
}
