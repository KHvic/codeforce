#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t,x;
    cin >> t;
    while(t--) {
        cin >> x;
        int cnt3 = 0;
        while(x%3==0) {
            cnt3++;
            x/=3;
        }
        int cnt2 = 0;
        while(x%2==0) {
            cnt2++;
            x/=2;
        }
        if(x != 1 || cnt2 > cnt3) cout << -1 << endl;
        else cout << (cnt3-cnt2)+cnt3 << endl;
    }
}
