#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> a;
vector<bool> valid; // whether a[i] is still a candidate

// idea: constructive algorithm
// eliminate candidate from the left by constructing leftmost bits
// candidate is always the kth item, initialized to be median(2^m - n)

// another way to solve this is to use binary search
// search for some number x, how many numbers is below it
// if(x-numBelow >= k) high = mid;
// else low = mid+1

ll howMany(int pos, char c) {
    ll res = 0;
    for(int i=0;i<a.size();i++) {
        if(valid[i] && a[i][pos] == c) res++;
    }
    return res;
}

void invalidate(int pos, char c) {
    for(int i=0;i<a.size();i++)
        if(a[i][pos] != c)
            valid[i] = false;
}

int main() {
    int t,n,m,v;
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        a.assign(n,"");
        valid.assign(n, true);
        ll k = ((1LL << m) - n + 1)/2; // median(2^m - n)
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        string res = "";
        for(int i=0;i<m;i++) {
            // how many 0 at pos i from set a
            ll num0 = howMany(i, '0');
            ll total0 = (1LL<<(m-1-i));
            ll left = total0 - num0;
            // more than half is 0 at pos i, then 0 is selected
            if(left >= k) {
                res += '0';
            } else {
                k -= left; //remove 0 candidates
                res += '1';
            }
            invalidate(i, res.back());
        }
        cout << res << endl;
    }
}
