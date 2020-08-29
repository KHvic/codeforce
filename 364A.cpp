#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// idea: sum of rectangle = sum(i..j)*sum(x..y)

int main(){
    fastio
    ll a;
    string s;
    cin >> a >> s;
    int n = s.size();
    unordered_map<ll, int> cnt;
    for(int i=0;i<n;i++) {
        ll sum = 0;
        for(int j=i;j<n;j++) {
            sum += s[j]-'0';
            cnt[sum]++;
        }
    }
    ll res = 0;
    if(a) {
        for(int i=0;i<n;i++) {
            ll sum = 0;
            for(int j=i;j<n;j++) {
                sum += s[j]-'0';
                if(sum!= 0 && a%sum == 0) res += cnt[a/sum];
            }
        }
    } else {
        ll zero = cnt[0];
        res += zero*zero;
        for(auto p : cnt) if(p.first) res += zero*p.second*2LL;
    }
    cout << res;
}
