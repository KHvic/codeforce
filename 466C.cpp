#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    scanf("%d",&n);
    vector<int> vals(n);
    ll total = 0;
    for(int i=0;i<n;i++) scanf("%d",&vals[i]), total += vals[i];

    ll res = 0;
    if(total%3 == 0) {
        ll cul = 0;
        ll target = total/3;

        // count one third from 0..i, find number of formable first part
        vector<ll> cntThird(n);
        ll cnt = 0;
        for(int i=0;i<n;i++) {
            cul += vals[i];
            if(cul == target) cnt++;
            cntThird[i] = cnt;
        }
        // do it backwards to form last part
        cul = 0;
        for(int i=n-1;i>1;i--) {
            cul += vals[i];
            // able to form last part
            if(cul==target) res += cntThird[i-2]; // need middle part buffer
        }
    }
    printf("%lld\n",res);
}
