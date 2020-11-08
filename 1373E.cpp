#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// observation 1: best to have as many 9 as possible, minimizing number of digits
// observation 2: two types of events could happen after adding a single digit
// given: (prefix) (999999...) (suffix+i)
// type-1 : suffix+i < 10, nothing much other than suffix change
// type-2 : suffix+i >= 10, carry result in (prefix+1) (000000...) (suffix+i)%10
// remaining part is to find all possible prefix based on the occurrences of these 2 types


int main(){
    fastio
    int t, n, k;
    cin >> t;
    while(t--) {
        ll res = 1e18;
        cin >> n >> k;
        // brute force number of 9s in middle
        for(int nine=0;nine<=150/9;nine++) {
            ll totalNine = nine*9;
            // try all suffix
            for(int suffix=0;suffix<10;suffix++) {
                int type1 = min(k+1, 10-suffix);
                int type2 = k+1 - type1;
                ll sum = type1 * totalNine + type2;
                for(int i=0;i<=k;i++) sum += (suffix+i) % 10;
                if(sum <= n) {
                    ll prefix = n - sum;
                    if(prefix % (k+1)) continue;
                    prefix /= (k+1);
                    ll prefixV;
                    // try to build smallest pref ix
                    // case 1: <= 8
                    if(prefix<=8) prefixV = prefix;
                    else {
                        // case 2: it must end with 8 (highest possible digit at the end reduce value in front)
                        prefix -= 8;
                        ll cnt9prefix = prefix/9; // number of 9s in middle, take 9 to reduce number of digit/front value
                        prefix %= 9;
                        prefixV = prefix;
                        for(int i=0;i<cnt9prefix;i++) prefixV = prefixV * 10 + 9;
                        prefixV = prefixV * 10 + 8;
                    }
                    ll actual = prefixV;
                    for(int i=0;i<nine;i++) actual = actual*10 + 9;
                    actual = actual*10 + suffix;
                    res = min(res, actual);
                }
            }
        }
        cout << (res<1e18 ? res : -1) << "\n";
    }
}
