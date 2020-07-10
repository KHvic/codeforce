#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, p;
    string s;
    cin >> n >> p;
    cin >> s;
    int mid = n/2;
    int lo,hi;
    p--; // make zero-indexed
    if(p>=mid) {
        lo = mid;
        hi = n-1;
    } else {
        lo = 0;
        hi = mid-1;
    }
    auto complement = [&](int x) {
        return n-1-x;
    };
    // shrink border if already match
    while(lo<=hi && s[lo] == s[complement(lo)]) lo++;
    while(lo<=hi && s[hi] == s[complement(hi)]) hi--;
    int res = 0;
    if(lo<=hi) {
        // move cursor to low or high depending on which is nearer
        int moveHi = abs(p-hi), moveLo = abs(p-lo);
        if(moveHi > moveLo) {
            res += moveLo;
        } else {
            res += moveHi;
        }
        res += (hi-lo);
        for(int i=lo;i<=hi;i++){
            int upcost = abs(s[i] - s[complement(i)]) % 26;
            int downcost = 26 - upcost;
            res += min(upcost, downcost);
        }
    }
    cout << res << "\n";
}
