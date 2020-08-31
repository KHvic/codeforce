#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

ll pow10[18];

ll solve(ll x) {
    if(x<10) return x;
    string s = to_string(x);
    int n = s.size();
    string tmp = s.substr(1,n-2);
    if(tmp.empty()) tmp = "0";
    ll withoutFirstLast = stoll(tmp);
    ll res = 9;
    for(int d=1;d<=9;d++) {
        for(int i=0;i<n-1;i++) {
            if(i<n-2) res += pow10[i];
            else if(i==n-2) {
                int first = s[0]-'0';
                if(d<first) res += pow10[i]; // dxxxd, 10^i possible xxx
                else if(d==first) res += withoutFirstLast + (d<=(x%10)); // dxxxd, with xxx possible, if d<=last then dxxxd is also possible
            }
        }
    }
    return res;
}

int main(){
    fastio
    ll a, b;
    cin >> a >> b;
    pow10[0] = 1;
    for(int i=1;i<18;i++) pow10[i] = pow10[i-1]*10;
    cout << solve(b) - solve(a-1);
}
